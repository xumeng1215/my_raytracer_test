/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:07:07 by mexu              #+#    #+#             */
/*   Updated: 2024/12/30 17:43:20 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math42.h"

t_interval	interval_init(double min, double max)
{
	t_interval	ret;

	ret.min = min;
	ret.max = max;
	return (ret);
}

double	clamp_with_interval(double t, t_interval i)
{
	if (t < i.min)
		return (i.min);
	if (t > i.max)
		return (i.max);
	return (t);
}

// double	interval_size(t_interval i)
// {
// 	return (i.max - i.min);
// }

// bool	interval_contains(t_interval i, double t)
// {
// 	return (t >= i.min && t <= i.max);
// }

// bool	interval_surrounds(t_interval i, double t)
// {
// 	return (t > i.min && t < i.max);
// }

// t_interval	empty_interval(void)
// {
// 	return (interval_init(INFINITY, -INFINITY));
// }

// t_interval	infinite_interval(void)
// {
// 	return (interval_init(-INFINITY, INFINITY));
// }