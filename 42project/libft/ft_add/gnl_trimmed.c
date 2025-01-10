/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_trimmed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:43:26 by fiftyblue         #+#    #+#             */
/*   Updated: 2024/12/12 10:44:38 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_trimmed(int fd)
{
	char	*tmp;
	char	*new;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}
