/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:01:12 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 20:45:59 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_map(int fd)
{
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		map = ft_strjoin(map, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && tmp[ft_strlenn(tmp) - 1] != '\n')
			tmp = ft_strjoin(tmp, "\n");
	}
	free(tmp);
	return (map);
}
