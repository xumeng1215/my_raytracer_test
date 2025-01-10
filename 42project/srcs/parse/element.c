/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:11:01 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/05 12:11:03 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	parse_color(t_world *world, char *str)
{
	int		i;
	char	**strarray;
	t_vec	rgb;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != ',')
			panic("color form", 0, 0, world);
	strarray = ft_split(str, ',');
	if (ft_strs_count(strarray) != 3)
		(ft_freematrix(&strarray), panic("color form", 0, 0, world));
	rgb.x = (double)ft_atoi(strarray[0]);
	rgb.y = (double)ft_atoi(strarray[1]);
	rgb.z = (double)ft_atoi(strarray[2]);
	if (!valid_rgb(rgb.x) || !valid_rgb(rgb.y) || !valid_rgb(rgb.z))
		(ft_freematrix(&strarray), panic("rgb: [0, 255]", 0, 0, world));
	ft_freematrix(&strarray);
	return (rgb);
}

t_vec	parse_coordinates(t_world *world, char *str)
{
	int		i;
	char	**strs;
	t_vec	coordinates;

	i = -1;
	while (str[++i])
		if (!is_float_char(str[i]) && str[i] != ',')
			panic("coordinates form", 0, 0, world);
	strs = ft_split(str, ',');
	if (ft_strs_count(strs) != 3)
		(ft_freematrix(&strs), panic("coordinates form", 0, 0, world));
	if (!ft_isfloat(strs[0]) || !ft_isfloat(strs[1]) || !ft_isfloat(strs[2]))
		(ft_freematrix(&strs)
			, panic("coordinates take floats only", 0, 0, world));
	coordinates.x = ft_atod(strs[0]);
	coordinates.y = ft_atod(strs[1]);
	coordinates.z = ft_atod(strs[2]);
	ft_freematrix(&strs);
	return (coordinates);
}

t_vec	parse_vector(t_world *world, char *str)
{
	int		i;
	char	**strs;
	t_vec	vector;

	i = -1;
	while (str[++i])
		if (!is_float_char(str[i]) && str[i] != ',')
			panic("vector form", 0, 0, world);
	strs = ft_split(str, ',');
	if (ft_strs_count(strs) != 3)
		(ft_freematrix(&strs), panic("vector form", 0, 0, world));
	if (!ft_isfloat(strs[0]) || !ft_isfloat(strs[1]) || !ft_isfloat(strs[2]))
		(ft_freematrix(&strs), panic("vector takes floats only", 0, 0, world));
	vector.x = ft_atod(strs[0]);
	vector.y = ft_atod(strs[1]);
	vector.z = ft_atod(strs[2]);
	if (!valid_vec(vector))
		(ft_freematrix(&strs), panic("vector range [-1, 1]", 0, 0, world));
	if (if_vec_zero(vector))
		panic("vec cannot be (0,0,0)", 0, 0, world);
	ft_freematrix(&strs);
	return (normalize(vector));
}
