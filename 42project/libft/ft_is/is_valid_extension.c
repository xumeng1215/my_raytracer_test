/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:25:28 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/09 21:37:38 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_valid_extension(char *str, char *extension)
{
	char	*ptr;

	if (!str || !extension)
		return (false);
	ptr = ft_strrchr(str, '.');
	if (ptr)
	{
		if (ft_strcmp(ptr, extension) == 0)
			return (true);
	}
	return (false);
}
