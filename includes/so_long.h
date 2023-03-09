/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:33:59 by hguillau          #+#    #+#             */
/*   Updated: 2023/02/27 18:16:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct t_data {
	char	*addr;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map;
	int		nb_collect;
	int		nb_column;
	int		nb_line;
	int		pos_player;
	int		act_collect;
	int		tempo;
	char	**anim;
	int		movement;
	int		e_dir;
}				t_data;

typedef struct s_img {
	void	*floor;
	void	*wall;
	void	*chest;
	void	*o_chest;
	void	*chara;
}				t_img;

//sprites
# define FLOOR		"./sprites/roolf.xpm"
# define WALL		"./sprites/newall.xpm"
# define CHARA		"./sprites/nechar5.xpm"
# define DRAGON		"./sprites/dragon.xpm"
# define DOOR		"./sprites/door.xpm"
# define O_DOOR		"./sprites/odoor.xpm"
# define CAPY2		"./sprites/capybara2.xpm"
# define CAPYD		"./sprites/capydead.xpm"
# define CAPYCIDE	"./sprites/capycide.xpm"
# define CD1 		"./sprites/cd1.xpm"
# define CD2 		"./sprites/cd2.xpm"
# define CD3 		"./sprites/cd3.xpm"
# define CD4 		"./sprites/cd4.xpm"
# define CD5 		"./sprites/cd5.xpm"
# define CD6 		"./sprites/cd6.xpm"

//fonctions
int		ft_line_size(char *str);
int		ft_column_size(char *str);
int		deal_key(int key, t_data *mlx);
int		ft_close_win(void);
void	ft_win(void);
void	ft_open_floor(int i, int j, t_data *mlx);
void	ft_secu(char *str, char *map);
void	ft_open_map(char *str, t_data *mlx);
void	ft_map_disptach(char *str, t_data *mlx);
void	ft_put_image(char *my_img, int i, int j, t_data *mlx);
void	ft_movement(int key, t_data *mlx);
void	ft_map_read(char c, int y, int z, t_data *mlx);
void	ft_move(int d, t_data *mlx);
void	ft_exit(t_data *mlx);
void	ft_replace(int act, int sui, t_data *mlx);
void	ft_act_is_p(int act, int sui, t_data *mlx);
void	ft_refresh(t_data *mlx, int pos, char img);
char	*ft_get_map(int fd);

//secu
int		ft_manque(char *str);
int		ft_strlen_bis(char *str);
int		ft_rect(char *str);
int		ft_close(char *str);
int		ft_first_is_close(char *str);
int		ft_last_is_close(char *str);
int		ft_column_are_close(char *str);
int		ft_strlen_bis(char *str);
int		ft_fichier_ber(char *map);

//donnee
int		ft_count_collectible(char *str);
int		ft_count_column(char *str);
int		ft_count_line(char *str);
int		ft_pos_player(char *str);
void	recup_donnee(char *map, t_data *mlx);

//bonus
int		ft_anim(t_data *mlx);
size_t	ft_find_c(char *str, int i);
void	ft_anim_set(t_data *mlx);
void	ft_refresh_anim(t_data *mlx, int pos, char *img);
void	ft_aff_mov(t_data *mlx);

//ennemis
void	ft_you_loose(void);
void	ft_replace_e(int act, int sui, t_data *mlx);
void	ennemi_move(t_data *mlx);
size_t	ft_find_ennemi(char *str, size_t i);

#endif
