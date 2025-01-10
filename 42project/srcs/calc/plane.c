/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:50:45 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 13:14:32 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
normal * (P - pos) == 0
normal * ((ray->pos + (ray->vec)t) - pos) = 0
normal * ray->pos + normal * ray->vec * t - normal * pos = 0
normal * ray->vec * t = normal * pos - normal * ray->pos
t = (normal * pos - normal * ray->pos) / normal * ray->vec
*/
double	plane_formula(t_ray *ray, t_vec pos, t_vec pl_normal)
{
	t_vec	oc;
	double	denominator;
	double	t;

	if (vec_dot(pl_normal, ray->vec) > EPSILON)
		pl_normal = vec_mul(pl_normal, -1);
	denominator = vec_dot((pl_normal), ray->vec);
	if (fabs(denominator) < EPSILON)
		return (-1);
	oc = vec_sub(ray->pos, pos);
	t = -vec_dot(pl_normal, oc) / denominator;
	if (t < EPSILON)
		return (-1);
	return (t);
}

double	pl_intersect(t_ray *ray, t_pl *plane)
{
	return (plane_formula(ray, plane->pos, plane->vec));
}

double	get_plane_color(t_world *world, t_pl *plane)
{
	t_vec	p;
	t_vec	n;
	double	dot;

	p = point_of_intersect(world->ray, world->ray->t);
	n = normalize(plane->vec);
	dot = vec_dot(world->ray->vec, n);
	if (dot > EPSILON && dot < 1)
		n = vec_mul(n, -1);
	return (compute_color(world, p, n, plane->rgb));
}
