/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:29:50 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/20 15:17:49 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(int d, t_data *mlx)
{
	if (mlx->map[d + mlx->pos_player] != '1'
		&& mlx->map[d + mlx->pos_player] != 'E')
	{
		mlx->movement++;
		ft_replace(mlx->pos_player, (mlx->pos_player + d), mlx);
	}
}

void	ft_replace(int act, int sui, t_data *mlx)
{
	char	tmp;

	tmp = mlx->map[act];
	if (mlx->map[act] == 'p')
		ft_act_is_p(act, sui, mlx);
	else if (mlx->map[sui] == 'C')
	{
		mlx->act_collect += 1;
		ft_exit(mlx);
		mlx->map[act] = '0';
		mlx->map[sui] = 'p';
	}
	else if (mlx->map[sui] == 'e')
		ft_win();
	else if (mlx->map[sui] == 'X')
		ft_you_loose();
	else
	{
		mlx->map[act] = mlx->map[sui];
		mlx->map[sui] = tmp;
	}
	mlx->pos_player = sui;
	ft_refresh(mlx, sui, mlx->map[sui]);
	ft_refresh(mlx, act, mlx->map[act]);
}

void	ft_act_is_p(int act, int sui, t_data *mlx)
{
	if (mlx->map[sui] == 'C')
	{
		mlx->act_collect += 1;
		ft_exit(mlx);
		mlx->map[act] = 'c';
		mlx->map[sui] = 'p';
	}
	else if (mlx->map[sui] == 'e')
		ft_win();
	else
	{
		mlx->map[act] = 'c';
		mlx->map[sui] = 'P';
	}
}
