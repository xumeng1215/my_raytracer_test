/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:21:41 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 14:30:22 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/*
yet to clean fd??
*/
void	panic(char *msg1, char *msg2, char *msg3, t_world *world)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg1)
		ft_putstr_fd(msg1, STDERR_FILENO);
	if (msg2)
		strerror(errno);
	if (msg3)
		ft_putstr_fd(msg3, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (world)
		cleanup(world);
	exit(1);
}
