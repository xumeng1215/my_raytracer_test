/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:12:46 by achiu             #+#    #+#             */
/*   Updated: 2025/01/07 13:14:43 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_objs	*ray_hit(t_world *world)
{
	t_list		*tmp;
	t_objs		*objs_;
	double		t;
	t_objs		*closest;

	world->ray->t = INFINITY;
	tmp = world->objs;
	closest = NULL;
	while (tmp)
	{
		objs_ = (t_objs *)tmp->content;
		if (objs_->type == SP)
			t = sp_intersect(world->ray, (t_sp *)objs_->data);
		else if (objs_->type == PL)
			t = pl_intersect(world->ray, (t_pl *)objs_->data);
		else if (objs_->type == CY)
			t = cy_intersect(world->ray, (t_cy *)objs_->data);
		if (t > EPSILON && t < world->ray->t)
		{
			world->ray->t = t;
			closest = objs_;
		}
		tmp = tmp->next;
	}
	return (closest);
}

/* get the P here seems making sense */
static int	get_color(t_world *world)
{
	t_objs	*obj;

	obj = ray_hit(world);
	if (obj)
	{
		if (obj->type == SP)
			return (get_sphear_color(world, (t_sp *)(obj->data)));
		else if (obj->type == PL)
			return (get_plane_color(world, (t_pl *)(obj->data)));
		else if (obj->type == CY)
			return (get_cylinder_color(world, (t_cy *)(obj->data)));
	}
	return (BLACK);
}

void	render(t_world *world)
{
	int		x;
	int		y;

	init_cam(world->cam);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			calc_ray(world, x, y);
			world->data->img_data[y * WIDTH + x] = get_color(world);
		}
	}
	mlx_put_image_to_window
		(world->data->mlx, world->data->win, world->data->img, 0, 0);
}
