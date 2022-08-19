/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:52:41 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 20:22:47 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manque(char *str)
{
	int		i;
	char	tab[4];

	i = 0;
	ft_bzero(tab, 4);
	while (str[i])
	{
		if (str[i] == 'P')
			tab[0]++;
		if (str[i] == 'C')
			tab[1]++;
		if (str[i] == 'E')
			tab[2]++;
		i++;
	}
	if (tab[0] != 1 || tab[1] < 1 || tab[2] < 1)
	{
		ft_printf("Erreur dans la configuration de la map\n");
		return (0);
	}
	return (1);
}

int	ft_strlen_bis(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	return (j);
}

int	ft_rect(char *str)
{
	int	i;
	int	j;
	int	k;

	k = ft_strlen_bis(str);
	i = k + 1;
	while (str[i])
	{
		j = ft_strlen_bis(str + i);
		if (j != k)
		{
			ft_printf("map non rectangulaire\n");
			return (0);
		}
		i += k + 1;
	}
	return (1);
}

int	ft_close(char *str)
{
	if (!ft_first_is_close(str))
	{
		ft_printf("first line open\n");
		return (0);
	}
	if (!ft_last_is_close(str))
	{
		ft_printf("last line open\n");
		return (0);
	}
	if (!ft_column_are_close(str))
	{
		ft_printf("column open\n");
		return (0);
	}
	return (1);
}

void	ft_secu(char *str, char *map)
{
	if (!ft_manque(str) || !ft_rect(str))
		exit(1);
	if (!ft_close(str) || !ft_fichier_ber(map))
		exit(1);
}
