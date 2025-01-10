/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:28:32 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 15:12:21 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* can reduce a bit calc tho if record the type */
double	get_cylinder_color(t_world *world, t_cy *cy)
{
	t_vec	p;
	t_vec	normal;
	t_vec	center_2_p;
	t_vec	proj;

	p = point_of_intersect(world->ray, world->ray->t);
	if (in_circle_range
		(world->ray, world->ray->t, cy->btm_c, cy->diameter / 2))
		normal = vec_rev(cy->vec);
	else if (in_circle_range
		(world->ray, world->ray->t, cy->top_c, cy->diameter / 2))
		normal = cy->vec;
	else
	{
		center_2_p = vec_sub(p, cy->center);
		proj = vec_mul(cy->vec, vec_dot(center_2_p, cy->vec));
		normal = normalize(vec_sub(center_2_p, proj));
	}
	return (compute_color(world, p, normal, cy->rgb));
}

// double	get_cylinder_color(t_world *world, t_cy *cylinder)
// {
// 	t_vec	p;
// 	t_vec	n;
// 	t_vec	proj;
// 	t_vec	center_to_p;

// 	p = point_of_intersect(world->ray, world->ray->t);
// 	center_to_p = vec_sub(p, cylinder->center);
// 	proj = vec_mul(cylinder->vec,
// 			vec_dot(center_to_p, normalize(cylinder->vec)));
// 	n = normalize(vec_sub(center_to_p, proj));
// 	return (compute_color(world, p, n, cylinder->rgb));
// }
