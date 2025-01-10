/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:55:14 by mexu              #+#    #+#             */
/*   Updated: 2024/12/30 13:47:31 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math42.h"
#include "miniRT.h"

t_vec	vec_init(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	return (vec_init(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	return (vec_init(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec	vec_mul(t_vec a, double t)
{
	return (vec_init(a.x * t, a.y * t, a.z * t));
}

t_vec	vec_rev(t_vec a)
{
	return (vec_init(-a.x, -a.y, -a.z));
}

// t_vec vec_add_multiple(int count, ...)
// {
// 	t_vec ret = {0, 0, 0};
// 	va_list args;
// 	va_start(args, count);

// 	int i = -1;
// 	while (++i < count)
// 	{
// 		t_vec vec = va_arg(args, t_vec);
// 		ret.x += vec.x;
// 		ret.y += vec.y;
// 		ret.z += vec.z;
// 	}
// 	va_end(args);
// 	return ret;
// }

// bool vec_near_zero(t_vec a)
// {
// 	const double s = 1e-8;

// 	return (fabs(a.x) < s && fabs(a.y) < s && fabs(a.z) < s);
// }

// t_vec vec_unit(t_vec a)
// {
// 	return (vec_div(a, vec_len(a)));
// }

// bool	if_vec_zero(t_vec vec)
// {
// 	return (fabs(vec.x) < EPSILON
// 		&& fabs(vec.y) < EPSILON && fabs(vec.z) < EPSILON);
// }

// t_vec	normalize(t_vec vec)
// {
// 	double	len;

// 	len = vec_len(vec);
// 	if (len < EPSILON)
// 		return (vec);
// 	return ((t_vec){vec.x / len, vec.y / len, vec.z / len});
// }

// t_vec	point_of_intersect(t_ray *ray, double t)
// {
// 	return (vec_add(ray->pos, vec_mul(ray->vec, t)));
// }
