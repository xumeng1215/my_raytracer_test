/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:05:09 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/28 08:59:30 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	prnt_vec(t_vec vec)
{
	printf("%.5f, %.5f, %.5f", vec.x, vec.y, vec.z);
}

// void	prnt_hit(t_hit *hit)
// {
// 	if (hit)
// 	{
// 		printf("hittable->t: %f\n", hit->t);
// 		if (hit->objs)
// 		{
// 			if (hit->objs->type == SP)
// 				prnt_sp((t_sp *)hit->objs->data);
// 			else if (hit->objs->type == PL)
// 				prnt_pl((t_pl *)hit->objs->data);
// 			else if (hit->objs->type == CY)
// 				prnt_cy((t_cy *)hit->objs->data);
// 		}
// 	}
// }

void	prnt_ray(t_ray *ray)
{
	printf("pos: ");
	prnt_vec(ray->pos);
	printf("\n");
	printf("vec: ");
	prnt_vec(ray->vec);
	printf("\n");
}

void	prnt_world(t_world *world)
{
	printf("========== ENV ==========\n");
	if (world->amb)
		printf("A,\t%.2f\t\t\t\t\t\t\t\t\t\t%.2f,%.2f,%.2f\n",
			world->amb->ratio,
			world->amb->rgb.x, world->amb->rgb.y, world->amb->rgb.z);
	if (world->cam)
	{
		printf("C\t");
		prnt_vec(world->cam->pos);
		printf("\t\t");
		prnt_vec(world->cam->vector);
		printf("\t\t%d\n", world->cam->fov);
	}
	if (world->lt)
	{
		printf("L\t");
		prnt_vec(world->lt->pos);
		printf("\t\t\t\t\t%.2f\t\t\t", world->lt->ratio);
		prnt_vec(world->lt->rgb);
		printf("\n");
	}
	if (world->objs)
		prnt_objs(world->objs);
}
