/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:31:29 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 13:14:17 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	get_positive_root(double a, double b, double discriminant)
{
	double	r1;
	double	r2;

	r1 = (-b - sqrt(discriminant)) / (2.0 * a);
	r2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (r1 > EPSILON && r2 > EPSILON)
		return (fmin(r1, r2));
	else if (r1 > EPSILON)
		return (r1);
	else if (r2 > EPSILON)
		return (r2);
	return (-1.0);
}

double	sp_intersect(t_ray *ray, t_sp *sphere)
{
	t_quadratic	qe;

	qe.oc = vec_sub(ray->pos, sphere->center);
	qe.a = vec_dot(ray->vec, ray->vec);
	qe.b = 2.0 * vec_dot(qe.oc, ray->vec);
	qe.c = vec_dot(qe.oc, qe.oc) \
			- (sphere->diameter / 2) * (sphere->diameter / 2);
	qe.discriminant = qe.b * qe.b - 4.0 * qe.a * qe.c;
	if (qe.discriminant < 0
		|| get_positive_root(qe.a, qe.b, qe.discriminant) < 0)
		return (-1);
	return (get_positive_root(qe.a, qe.b, qe.discriminant));
}

double	get_sphear_color(t_world *world, t_sp *sphere)
{
	t_vec	p;
	t_vec	n;

	p = point_of_intersect(world->ray, world->ray->t);
	n = normalize(vec_sub(p, sphere->center));
	return (compute_color(world, p, n, sphere->rgb));
}
