/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:40:12 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/20 15:29:56 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_close_win(void)
{
	exit(1);
}

int	deal_key(int key, t_data *mlx)
{
	if (key == 53)
		ft_close_win();
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		ft_movement(key, mlx);
		ennemi_move(mlx);
	}
	return (0);
}

void	ft_put_image(char *my_img, int i, int j, t_data *mlx)
{
	int		w_img;
	int		h_img;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, my_img, &w_img, &h_img);
	if (!img)
	{
		ft_printf("can't open %s\n", my_img);
		exit (12);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, i, j);
}

int	main(int ac, char **av)
{
	t_data	mlx;
	int		fd;
	char	*map;

	(void) ac;
	fd = open(av[1], O_RDONLY);
	map = ft_get_map(fd);
	ft_anim_set(&mlx);
	recup_donnee(map, &mlx);
	ft_secu(map, av[1]);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (ft_column_size(map) * 32),
			(ft_line_size(map) * 32), "so_long");
	ft_open_map(map, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, ft_close_win, 0);
	mlx_key_hook(mlx.win_ptr, deal_key, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_anim, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
