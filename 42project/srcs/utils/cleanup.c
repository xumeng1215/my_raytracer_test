/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:35 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 15:12:38 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_objs(void	*obj_ptr)
{
	t_objs	*obj;

	obj = (t_objs *)obj_ptr;
	if (obj)
	{
		if (obj->data)
		{
			if (obj->type == SP)
				free((t_sp *)obj->data);
			else if (obj->type == PL)
				free((t_pl *)obj->data);
			if (obj->type == CY)
				free((t_cy *)obj->data);
		}
		free(obj);
	}
}

void	cleanup(t_world *world)
{
	if (world->amb)
		free(world->amb);
	if (world->cam)
		free(world->cam);
	if (world->lt)
		free(world->lt);
	if (world->objs)
		ft_lstclear(&world->objs, free_objs);
	if (world->ray)
		free(world->ray);
}

#if defined(__linux__)

// free(world->world->data);
void	free_ptrs(t_world *world)
{
	if (world->data->img)
		mlx_destroy_image(world->data->mlx, world->data->img);
	if (world->data->win)
		mlx_destroy_window(world->data->mlx, world->data->win);
	if (world->data->mlx)
		mlx_destroy_display(world->data->mlx);
	if (world->data)
		free(world->data);
	cleanup(world);
	exit(EXIT_SUCCESS);
}

#elif defined(__APPLE__)

/* freeing mlx directly will cause leaks */
void	free_ptrs(t_world *world)
{
	if (world->data->img)
		mlx_destroy_image(world->data->mlx, world->data->img);
	if (world->data->win)
		mlx_destroy_window(world->data->mlx, world->data->win);
	if (world->data)
		free(world->data);
	cleanup(world);
	exit(EXIT_SUCCESS);
}

#endif
