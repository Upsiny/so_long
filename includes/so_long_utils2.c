/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:12:23 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 16:13:26 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_read(char c, int y, int z, t_data *mlx)
{
	if (c == '1')
		ft_put_image(WALL, y, z, mlx);
	if (c == 'C')
		ft_put_image(CAPY2, y, z, mlx);
	if (c == 'P')
		ft_put_image(CHARA, y, z, mlx);
	if (c == 'E')
		ft_put_image(DOOR, y, z, mlx);
	if (c == 'e')
		ft_put_image(O_DOOR, y, z, mlx);
	if (c == 'X')
		ft_put_image(DRAGON, y, z, mlx);
	if (c == 'c')
		ft_put_image(CD1, y, z, mlx);
	if (c == 'p')
		ft_put_image(CAPYCIDE, y, z, mlx);
}

void	ft_movement(int key, t_data *mlx)
{
	if (key == 0)
		ft_move(-1, mlx);
	if (key == 2)
		ft_move(1, mlx);
	if (key == 1)
		ft_move(mlx->nb_column + 1, mlx);
	if (key == 13)
		ft_move((-mlx->nb_column - 1), mlx);
}

void	ft_exit(t_data *mlx)
{
	int	i;

	i = 0;
	if (mlx->act_collect == mlx->nb_collect)
	{
		while (mlx->map[i])
		{
			if (mlx->map[i] == 'E')
			{
				mlx->map[i] = 'e';
				ft_refresh(mlx, i, mlx->map[i]);
			}
			i++;
		}
	}
}

void	ft_win(void)
{
	ft_printf("Extermination termine, extraction autorise, Felicitation\n");
	exit(1);
}

void	ft_refresh(t_data *mlx, int pos, char img)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= pos && mlx->map[i])
	{
		if (mlx->map[i] == '\n')
			j++;
		i++;
	}
	while (mlx->map[i] != '\n')
	{
		i--;
		k++;
	}
	ft_put_image(FLOOR, (k - 2) * 32, j * 32, mlx);
	ft_map_read(img, (k - 2) * 32, j * 32, mlx);
}
