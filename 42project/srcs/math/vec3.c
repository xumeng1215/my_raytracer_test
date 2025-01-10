/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:47:06 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/30 13:47:17 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math42.h"
#include "miniRT.h"

bool	if_vec_zero(t_vec vec)
{
	return (fabs(vec.x) < EPSILON
		&& fabs(vec.y) < EPSILON && fabs(vec.z) < EPSILON);
}

t_vec	normalize(t_vec vec)
{
	double	len;

	len = vec_len(vec);
	if (len < EPSILON)
		return (vec);
	return ((t_vec){vec.x / len, vec.y / len, vec.z / len});
}

t_vec	point_of_intersect(t_ray *ray, double t)
{
	return (vec_add(ray->pos, vec_mul(ray->vec, t)));
}
