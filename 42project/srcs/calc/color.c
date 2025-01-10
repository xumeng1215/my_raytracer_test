/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:33:20 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 13:10:31 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* 
pow(LinearValue, 1 / gamma)
normally gamma is 2.2 but prefer using 1.2
*/
t_vec	gamma_correction(t_vec color)
{
	const double	gamma = 1.2;

	color.x = pow(color.x / 255.0, 1.0 / gamma) * 255.0;
	color.y = pow(color.y / 255.0, 1.0 / gamma) * 255.0;
	color.z = pow(color.z / 255.0, 1.0 / gamma) * 255.0;
	return (color);
}

// get color with intensity
static double	calc_color(t_world *world, t_vec rgb, double intensity)
{
	t_vec		color;
	int			x;
	int			y;
	int			z;
	t_interval	range;

	(void)world;
	range = interval_init(0.0, 255.0);
	color = vec_mul(rgb, intensity);
	color = gamma_correction(color);
	x = (int)clamp_with_interval(color.x, range);
	y = (int)clamp_with_interval(color.y, range);
	z = (int)clamp_with_interval(color.z, range);
	return ((x << 16) | (y << 8) | z);
}

/* self intersection?? I cannot tell the diff tho */
t_ray	shadow_ray(t_world *world, t_vec p, t_vec n)
{
	t_ray	ray;

	ray.vec = normalize(vec_sub(world->lt->pos, p));
	ray.pos = vec_add(p, vec_mul(n, EPSILON));
	return (ray);
}

/* edge case: obj is behind the light pos */
int	ray_trace(t_world *world, t_vec p, t_vec n)
{
	t_ray	ray;
	double	t;
	t_list	*tmp;
	t_objs	*obj;

	ray = shadow_ray(world, p, n);
	tmp = world->objs;
	while (tmp)
	{
		obj = (t_objs *)tmp->content;
		if (obj->type == SP)
			t = sp_intersect(&ray, (t_sp *)obj->data);
		else if (obj->type == PL)
			t = pl_intersect(&ray, (t_pl *)obj->data);
		else if (obj->type == CY)
			t = cy_intersect(&ray, (t_cy *)obj->data);
		if (t > EPSILON && t < vec_len(vec_sub(world->lt->pos, p)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* 
I = max(0, Normal⋅Light) * light_ratio / (distance * distance) + ambient
with the / pow(distance, 2) doesn't look nice tho
This function gets intensity first
soft shadow to solve obj being all in shadow case.
*/
double	compute_color(t_world *world, t_vec p, t_vec n, t_vec rgb)
{
	int		shadow;
	t_vec	light;
	double	intensity;

	intensity = 0;
	shadow = ray_trace(world, p, n);
	light = normalize(vec_sub(world->lt->pos, p));
	if (!shadow)
		intensity = ft_fmax(vec_dot(n, light), 0.0) * world->lt->ratio;
	else
		intensity = 0.5 * ft_fmax(vec_dot(n, light), 0.0) * world->lt->ratio;
	intensity += world->amb->ratio;
	return (calc_color(world, rgb, intensity));
}
