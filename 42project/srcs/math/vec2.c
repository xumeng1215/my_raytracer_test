/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:58 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/30 13:45:57 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math42.h"
#include "miniRT.h"

t_vec	vec_div(t_vec a, double t)
{
	return (vec_mul(a, 1 / t));
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	return (vec_init
		(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

double	vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_len_sq(t_vec a)
{
	return (vec_dot(a, a));
}

double	vec_len(t_vec a)
{
	return (sqrt(vec_len_sq(a)));
}
