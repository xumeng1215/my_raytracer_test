/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:35:26 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/05 17:06:05 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_sphere(t_world *world, char **strarray)
{
	t_objs	*obj;
	t_sp	*sphere;

	if (ft_strs_count(strarray) != 4)
		(ft_freematrix(&strarray), panic("sphere got three argv", 0, 0, world));
	obj = malloc(sizeof(t_objs));
	if (!obj)
		panic(0, "fatal", 0, world);
	obj->type = SP;
	sphere = malloc(sizeof(t_sp));
	if (!sphere)
		panic(0, "fatal", 0, world);
	sphere->center = parse_coordinates(world, strarray[1]);
	if (!ft_isfloat(strarray[2]) || ft_atod(strarray[2]) < 0)
		(ft_freematrix(&strarray)
			, panic("sphere diameter: positive float", 0, 0, world));
	sphere->diameter = ft_atod(strarray[2]);
	sphere->rgb = parse_color(world, strarray[3]);
	obj->data = (void *)sphere;
	ft_lstadd_back(&world->objs, ft_lstnew((void *)obj));
}

void	parse_plane(t_world *world, char **strarray)
{
	t_objs	*obj;
	t_pl	*plane;

	if (ft_strs_count(strarray) != 4)
		(ft_freematrix(&strarray), panic("plane got three argv", 0, 0, world));
	obj = malloc(sizeof(t_objs));
	if (!obj)
		panic(0, "fatal", 0, world);
	obj->type = PL;
	plane = malloc(sizeof(t_pl));
	if (!plane)
		panic(0, "fatal", 0, world);
	plane->pos = parse_coordinates(world, strarray[1]);
	plane->vec = parse_vector(world, strarray[2]);
	plane->rgb = parse_color(world, strarray[3]);
	obj->data = (void *)plane;
	ft_lstadd_back(&world->objs, ft_lstnew((void *)obj));
}

void	parse_cylinder(t_world *world, char **strarray)
{
	t_objs	*obj;
	t_cy	*cy;

	if (ft_strs_count(strarray) != 6)
		(ft_freematrix(&strarray), panic("cy got six argv", 0, 0, world));
	obj = malloc(sizeof(t_objs));
	if (!obj)
		panic(0, "fatal", 0, world);
	obj->type = CY;
	cy = malloc(sizeof(t_cy));
	if (!cy)
		panic(0, "fatal", 0, world);
	cy->center = parse_coordinates(world, strarray[1]);
	cy->vec = parse_vector(world, strarray[2]);
	cy->diameter = parse_len(world, strarray[3], strarray);
	cy->height = parse_len(world, strarray[4], strarray);
	cy->rgb = parse_color(world, strarray[5]);
	cy->top_c = vec_add(cy->center, vec_mul(cy->vec, cy->height / 2));
	cy->btm_c = vec_sub(cy->center, vec_mul(cy->vec, cy->height / 2));
	obj->data = (void *)cy;
	ft_lstadd_back(&world->objs, ft_lstnew((void *)obj));
}
