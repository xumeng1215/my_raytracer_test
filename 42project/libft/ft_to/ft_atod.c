/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:39:11 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/03 10:05:37 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_fraction(char *str)
{
	double	fraction_base;
	double	fraction;

	fraction_base = 10.0;
	fraction = 0;
	while (*str && ft_isdigit(*str))
	{
		fraction += (*str - '0') / fraction_base;
		fraction_base *= 10.0;
		str++;
	}
	return (fraction);
}

/*
cannot handle !str || *str = NULL
*/
double	ft_atod(char *str)
{
	double	r;
	double	s;
	double	fraction;

	fraction = 0.0;
	s = 1;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		fraction = get_fraction(++str);
	return (s * (r + fraction));
}
