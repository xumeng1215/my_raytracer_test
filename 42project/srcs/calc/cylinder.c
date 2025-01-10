/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:32:41 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/31 12:36:28 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	in_circle_range(t_ray *ray, double t, t_vec center, double radius)
{
	t_vec	p;

	if (t < EPSILON)
		return (false);
	p = point_of_intersect(ray, t);
	return (vec_len(vec_sub(p, center)) <= radius);
}

double	intersect_cy_cap(t_ray *ray, t_cy *cy)
{
	double		t1;
	double		t2;
	t_vec		top_center;
	t_vec		btm_center;
	double		t;

	btm_center = vec_sub(cy->center, vec_mul(cy->vec, cy->height / 2));
	t1 = plane_formula(ray, btm_center, cy->vec);
	top_center = vec_add(cy->center, vec_mul(cy->vec, cy->height / 2));
	t2 = plane_formula(ray, top_center, cy->vec);
	t = -1.0;
	if (in_circle_range(ray, t1, btm_center, cy->diameter / 2))
		t = t1;
	if (in_circle_range(ray, t2, top_center, cy->diameter / 2))
		if (t < 0 || t2 < t)
			t = t2;
	return (t);
}

// cy->center using cap center
// double	intersect_cy_cap(t_ray *ray, t_cy *cy)
// {
// 	double		t1;
// 	double		t2;
// 	t_vec		top_center;
// 	double		t;

// 	t1 = plane_formula(ray, cy->center, cy->vec);
// 	top_center = vec_add(cy->center, vec_mul(cy->vec, cy->height));
// 	t2 = plane_formula(ray, top_center, cy->vec);
// 	t = -1.0;
// 	if (in_circle_range(ray, t1, cy->center, cy->diameter / 2))
// 		t = t1;
// 	if (in_circle_range(ray, t2, top_center, cy->diameter / 2))
// 		if (t < 0 || t2 < t)
// 			t = t2;
// 	return (t);
// }

// fabs(height) <= cy->height / 2
// height >= 0 && height <= cy->height
// height >= EPSILON || cy->height - fabs(height) <= EPSILON
bool	in_height_range(t_ray *ray, t_cy *cy, double t)
{
	t_vec	p;
	double	height;

	p = point_of_intersect(ray, t);
	height = vec_dot(vec_sub(p, cy->center), cy->vec);
	return (fabs(height) <= cy->height / 2);
}

double	intersect_cy_side(t_ray *ray, t_cy *cy)
{
	t_quadratic	q;
	t_vec		w;
	double		t;

	q.oc = vec_sub(ray->pos, cy->center);
	w = vec_cross(ray->vec, cy->vec);
	q.a = vec_dot(w, w);
	q.b = 2 * vec_dot(w, vec_cross(q.oc, cy->vec));
	q.c = vec_dot(vec_cross(q.oc, cy->vec), vec_cross(q.oc, cy->vec))
		- pow(cy->diameter / 2, 2) * vec_dot(cy->vec, cy->vec);
	q.discriminant = q.b * q.b - 4 * q.a * q.c;
	if (q.discriminant < 0)
		return (-1.0);
	t = get_positive_root(q.a, q.b, q.discriminant);
	if (t < EPSILON || !in_height_range(ray, cy, t))
		return (-1.0);
	return (t);
}

double	cy_intersect(t_ray *ray, t_cy *cy)
{
	double	t_side;
	double	t_cap;

	t_side = intersect_cy_side(ray, cy);
	t_cap = intersect_cy_cap(ray, cy);
	if (t_side < 0 && t_cap < 0)
		return (-1.0);
	else if (t_side < 0)
		return (t_cap);
	else if (t_cap < 0)
		return (cy->type = SIDE, t_side);
	else if (t_side > t_cap)
		return (t_cap);
	return (cy->type = SIDE, t_side);
}
