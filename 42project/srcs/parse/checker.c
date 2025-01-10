/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:24:50 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/18 09:46:46 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_float_char(char c)
{
	return (ft_isdigit(c) || c == '+' || c == '-' || c == '.');
}

bool	valid_ratio(char *str)
{
	return (ft_isfloat(str)
		&& ft_atod(str) >= 0.0 && ft_atod(str) <= 1.0);
}

bool	valid_rgb(int nbr)
{
	return (nbr >= 0 && nbr <= 255);
}

bool	valid_vec(t_vec vec)
{
	return (vec.x >= -1 && vec.x <= 1
		&& vec.y >= -1 && vec.y <= 1
		&& vec.z >= -1 && vec.z <= 1);
}

double	parse_len(t_world *world, char *str, char **strarray)
{
	if (!ft_isfloat(str) || ft_atod(str) < 0)
		(ft_freematrix(&strarray), panic("len: positive float", 0, 0, world));
	return (ft_atod(str));
}
