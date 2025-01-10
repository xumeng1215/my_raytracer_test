/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:28 by achiu             #+#    #+#             */
/*   Updated: 2025/01/07 15:12:51 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec	rotate_y(t_vec vec, double angle)
{
	t_vec	result;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = cos_a * vec.x + sin_a * vec.z;
	result.y = vec.y;
	result.z = -sin_a * vec.x + cos_a * vec.z;
	return (result);
}

static t_vec	rotate_x(t_vec vec, double angle)
{
	t_vec	result;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	result.x = vec.x;
	result.y = cos_a * vec.y - sin_a * vec.z;
	result.z = sin_a * vec.y + cos_a * vec.z;
	return (result);
}

static int	hook_keys(int key, void *param)
{
	t_world	*world;

	world = (t_world *)param;
	if (key == ESC)
		free_ptrs(world);
	if (key == LEFT)
		world->cam->vector = rotate_y(world->cam->vector, M_PI / 18);
	else if (key == RIGHT)
		world->cam->vector = rotate_y(world->cam->vector, -M_PI / 18);
	else if (key == UP)
		world->cam->vector = rotate_x(world->cam->vector, M_PI / 18);
	else if (key == DOWN)
		world->cam->vector = rotate_x(world->cam->vector, -M_PI / 18);
	render(world);
	return (0);
}

static int	close_window(void *param)
{
	free_ptrs((t_world *)param);
	return (0);
}

void	init_mlxdata(t_world *world)
{
	world->data = malloc(sizeof(t_data));
	if (!world->data)
		panic(0, "malloc", 0, world);
	ft_memset(world->data, 0, sizeof(t_data));
	if (WIDTH <= 0 || HEIGHT <= 0)
		panic("Invalid width or height", 0, 0, world);
	world->data->mlx = mlx_init();
	if (!world->data->mlx)
		free_ptrs(world);
	world->data->win
		= mlx_new_window(world->data->mlx, WIDTH, HEIGHT, "miniRT");
	if (!world->data->win)
		free_ptrs(world);
	world->data->img = mlx_new_image(world->data->mlx, WIDTH, HEIGHT);
	if (world->data->img == NULL)
		free_ptrs(world);
	world->data->img_data = (int *)mlx_get_data_addr
		(world->data->img, &(int){32}, &(int){WIDTH * 4}, &(int){0});
	mlx_key_hook(world->data->win, (int (*)())hook_keys, world);
	mlx_hook(world->data->win, 17, 0, close_window, world);
}
