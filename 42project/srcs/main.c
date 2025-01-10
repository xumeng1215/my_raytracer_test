/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:38:36 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 12:22:07 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* prnt_world(&world); */
int	main(int ac, char **av)
{
	t_world	world;

	ft_memset(&world, 0, sizeof(t_world));
	parser(ac, av, &world);
	init_mlxdata(&world);
	render(&world);
	mlx_loop(world.data->mlx);
	cleanup(&world);
}
