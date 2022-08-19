/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:04:49 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 13:11:53 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collectible(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			j++;
		i++;
	}
	return (j);
}

int	ft_count_column(char *str)
{
	int	i;

	i = ft_strlen_bis(str);
	return (i);
}

int	ft_count_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	ft_pos_player(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P' || str[i] == 'p')
			return (i);
		i++;
	}
	return (i);
}

void	recup_donnee(char *map, t_data *mlx)
{
	mlx->map = map;
	if (!mlx->movement)
		mlx->movement = 0;
	mlx->e_dir = 1;
	mlx->act_collect = 0;
	mlx->nb_collect = ft_count_collectible(map);
	mlx->nb_column = ft_count_column(map);
	mlx->nb_line = ft_count_line(map);
	mlx->pos_player = ft_pos_player(map);
}
