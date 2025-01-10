/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:49:07 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/30 12:25:04 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	prnt_sp(t_sp *sphere)
{
	printf("sp\t");
	prnt_vec(sphere->center);
	printf("\t\t\t\t\t\t%.2f\t\t\t", sphere->diameter);
	prnt_vec(sphere->rgb);
}

void	prnt_pl(t_pl *plane)
{
	printf("pl\t");
	prnt_vec(plane->pos);
	printf("\t\t\t");
	prnt_vec(plane->vec);
	printf("\t\t\t\t\t");
	prnt_vec(plane->rgb);
}

void	prnt_cy(t_cy *cylinder)
{
	printf("cy\t");
	prnt_vec(cylinder->center);
	printf("\t\t");
	prnt_vec(cylinder->vec);
	printf("\t\t%.2f\t", cylinder->diameter);
	printf("%.2f\t\t", cylinder->height);
	prnt_vec(cylinder->rgb);
}

void	prnt_objs(t_list *objs)
{
	t_objs	*ptr;

	printf("\n========== OBJS ==========\n");
	while (objs)
	{
		ptr = (t_objs *)objs->content;
		if (ptr->type == SP)
			prnt_sp((t_sp *)ptr->data);
		else if (ptr->type == PL)
			prnt_pl((t_pl *)ptr->data);
		else if (ptr->type == CY)
			prnt_cy((t_cy *)ptr->data);
		printf("\n");
		objs = objs->next;
	}
}
