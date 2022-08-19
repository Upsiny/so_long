/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:39:39 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 13:11:34 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_anim_set(t_data *mlx)
{
	char	**anim;

	anim = malloc(sizeof(char *) * 7);
	anim[0] = "./sprites/cd1.xpm";
	anim[1] = "./sprites/cd2.xpm";
	anim[2] = "./sprites/cd3.xpm";
	anim[3] = "./sprites/cd4.xpm";
	anim[4] = "./sprites/cd5.xpm";
	anim[5] = "./sprites/cd6.xpm";
	anim[6] = NULL;
	mlx->anim = anim;
}

size_t	ft_find_c(char *str, int i)
{
	while (str[i] && str[i] != 'c')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	ft_anim(t_data *mlx)
{
	size_t	i;
	int		j;

	j = mlx->tempo / 20;
	if (!mlx->tempo || j >= 5)
	{
		j = 0;
		mlx->tempo = 0;
	}
	if (!mlx->anim[j])
	{
		ft_printf("can't open %s\n", *mlx->anim[j]);
		exit(1);
	}
	i = ft_find_c(mlx->map, 0);
	while (i > 0 && i < ft_strlen(mlx->map))
	{
		ft_refresh_anim(mlx, i, mlx->anim[j]);
		i = ft_find_c(mlx->map, i + 1);
	}
	mlx->tempo++;
	ft_aff_mov(mlx);
	return (0);
}

void	ft_refresh_anim(t_data *mlx, int pos, char *img)
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
	ft_put_image(img, (k - 2) * 32, j * 32, mlx);
}

void	ft_aff_mov(t_data *mlx)
{
	char	*nb;

	nb = ft_itoa(mlx->movement);
	ft_put_image(WALL, 0, 0, mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 5, 0xFA0000, nb);
	free(nb);
}
