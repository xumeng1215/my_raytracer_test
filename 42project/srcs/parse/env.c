/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:51:38 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/12 23:31:12 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_ambient(t_world *world, char **strarray)
{
	if (world->amb)
		(ft_freematrix(&strarray)
			, panic("can only have one ambient light", 0, 0, world));
	if (ft_strs_count(strarray) != 3)
		(ft_freematrix(&strarray)
			, panic("ambient has two argv only", 0, 0, world));
	if (!valid_ratio(strarray[1]))
		(ft_freematrix(&strarray), panic("ambient ratio form", 0, 0, world));
	world->amb = malloc(sizeof(t_amb));
	if (!world->amb)
		panic(0, "fatal", 0, world);
	world->amb->ratio = ft_atod(strarray[1]);
	world->amb->rgb = parse_color(world, strarray[2]);
}

void	parse_camera(t_world *world, char **strarray)
{
	if (world->cam)
		(ft_freematrix(&strarray), panic("one cam only", 0, 0, world));
	if (ft_strs_count(strarray) != 4)
		(ft_freematrix(&strarray), panic("camera got three argv", 0, 0, world));
	world->cam = malloc(sizeof(t_cam));
	if (!world->cam)
		panic(0, "fatal", 0, world);
	world->cam->pos = parse_coordinates(world, strarray[1]);
	world->cam->vector = parse_vector(world, strarray[2]);
	if (!ft_isnbr(strarray[3]))
		(ft_freematrix(&strarray), panic("fov: 0-180", 0, 0, world));
	world->cam->fov = ft_atoi(strarray[3]);
	if (world->cam->fov < 0 || world->cam->fov > 180)
		(ft_freematrix(&strarray), panic("fov: 0-180", 0, 0, world));
}

void	parse_light(t_world *world, char **strarray)
{
	if (world->lt)
		(ft_freematrix(&strarray), panic("one lt only", 0, 0, world));
	if (ft_strs_count(strarray) != 4)
		(ft_freematrix(&strarray), panic("lt got three argv", 0, 0, world));
	world->lt = malloc(sizeof(t_light));
	if (!world->lt)
		panic(0, "fatal", 0, world);
	world->lt->pos = parse_coordinates(world, strarray[1]);
	if (!valid_ratio(strarray[2]))
		(ft_freematrix(&strarray), panic("light ratio form", 0, 0, world));
	world->lt->ratio = ft_atod(strarray[2]);
	world->lt->rgb = parse_color(world, strarray[3]);
}
