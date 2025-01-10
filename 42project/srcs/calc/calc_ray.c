/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:18:42 by achiu             #+#    #+#             */
/*   Updated: 2025/01/07 15:12:03 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_cam(t_cam *cam)
{
	t_vec	world_up;

	cam->height = 2.0f * tan((cam->fov * M_PI) / 180.0f / 2.0f);
	cam->width = cam->height * (double)WIDTH / (double)HEIGHT;
	world_up = (t_vec){0.0f, 1.0f, 0.0f};
	cam->forward = normalize(cam->vector);
	if (if_vec_zero(vec_cross(cam->forward, world_up)))
	{
		if (vec_dot(cam->forward, world_up) > 0)
			cam->right = (t_vec){1.0f, 0.0f, 0.0f};
		else
			cam->right = (t_vec){-1.0f, 0.0f, 0.0f};
	}
	else
		cam->right = normalize(vec_cross(cam->forward, world_up));
	cam->up = normalize(vec_cross(cam->right, cam->forward));
}

static void	cam_project_ray(t_cam *cam, int x, int y)
{
	float	u;
	float	v;

	u = ((x - WIDTH / 2.0) / WIDTH) * cam->width;
	v = ((HEIGHT / 2.0 - y) / HEIGHT) * cam->height;
	cam->dir = vec_add(
			vec_add(vec_mul(cam->right, u), vec_mul(cam->up, v)),
			cam->forward);
}

/* not using this one 
t_vec	ray_vec_by_focal(t_cam *cam, int x, int y)
{
	t_vec	ray_dir;
	double	fov_factor;

	fov_factor = tan(cam->fov * M_PI / 360.0);
	ray_dir = (t_vec){((x - WIDTH / 2.0) / WIDTH) * fov_factor,
		((HEIGHT / 2.0 - y) / HEIGHT) * fov_factor * HEIGHT / WIDTH,
		FOCAL_DIST};
	return (normalize(ray_dir));
}
*/

// world->ray->vec = ray_vec_by_focal(world->cam, x, y);
void	calc_ray(t_world *world, int x, int y)
{
	world->ray->pos
		= (t_vec){world->cam->pos.x, world->cam->pos.y, world->cam->pos.z};
	cam_project_ray(world->cam, x, y);
	world->ray->vec = normalize(world->cam->dir);
}
