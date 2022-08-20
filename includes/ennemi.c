/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:48:10 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/20 15:29:58 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_you_loose(void)
{
	ft_printf("un dragon n'est pas aussi simple a tuer qu'un capybara !\n");
	exit(1);
}

size_t	ft_find_ennemi(char *str, size_t i)
{
	while (str[i] && str[i] != 'X')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

void	ennemi_move(t_data *mlx)
{
	size_t	i;

	i = ft_find_ennemi(mlx->map, 0);
	while (i > 0 && i < ft_strlen(mlx->map))
	{
		if (mlx->map[i + mlx->e_dir] == '0' && mlx->map[i + mlx->e_dir] != 'P')
		{
			mlx->map[i] = '0';
			mlx->map[i + mlx->e_dir] = 'X';
			ft_refresh(mlx, i, '0');
			ft_refresh(mlx, mlx->e_dir + i, 'X');
		}
		else
		{
			mlx->e_dir *= -1;
		}
		i = ft_find_ennemi(mlx->map, i + mlx->e_dir + 1);
	}
}
