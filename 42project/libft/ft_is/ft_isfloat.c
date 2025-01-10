/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:11:19 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/09 21:20:37 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isfloat(char *str)
{
	int		dot;
	bool	has_digit;

	if (!str || !*str)
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	dot = 0;
	has_digit = false;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = true;
		else if (*str == '.')
			dot++;
		else
			return (false);
		str++;
	}
	return (has_digit && dot <= 1);
}
