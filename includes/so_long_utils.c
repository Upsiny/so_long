/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:03:31 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/20 15:17:57 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_column_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	ft_line_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

void	ft_open_floor(int i, int j, t_data *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x <= j)
	{
		y = 0;
		while (y <= i)
		{
			ft_put_image(FLOOR, x, y, mlx);
			y += 32;
		}
		x += 32;
	}
}

void	ft_map_dispatch(char *str, t_data *mlx)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	while (str[x])
	{
		ft_map_read(str[x], y, z, mlx);
		y += 32;
		if (str[x] == '\n')
		{
			y = 0;
			z += 32;
		}
		x++;
	}
}

void	ft_open_map(char *str, t_data *mlx)
{
	int		i;
	int		j;

	i = ft_line_size(str) * 32;
	j = ft_column_size(str) * 32;
	ft_open_floor(i, j, mlx);
	ft_map_dispatch(str, mlx);
	ft_exit(mlx);
}
