/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:48:10 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 15:56:28 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_you_loose(void)
{
	ft_printf("un dragon n'est pas aussi simple a tuer au'un capybara !\n");
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

void	ft_replace_e(int act, int sui, t_data *mlx)
{
	char	tmp;

	tmp = mlx->map[act];
	mlx->map[act] = mlx->map[sui];
	mlx->map[sui] = tmp;
	ft_refresh(mlx, sui, mlx->map[sui]);
	ft_refresh(mlx, act, mlx->map[act]);
}

void	ennemi_move(t_data *mlx)
{
	size_t	i;

	i = ft_find_ennemi(mlx->map, 0);
	while (i > 0 && i < ft_strlen(mlx->map))
	{
		if (mlx->map[i + mlx->e_dir] == '0')
		{
			mlx->map[i] = '0';
			mlx->map[i + mlx->e_dir] = 'X';
		}
		else
		{
			mlx->e_dir *= -1;
		}
		ft_refresh(mlx, i, '0');
		ft_refresh(mlx, mlx->e_dir + i, 'X');
		i = ft_find_ennemi(mlx->map, i + mlx->e_dir + 1);
	}
}
