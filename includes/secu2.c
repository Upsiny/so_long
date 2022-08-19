/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:09:52 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 20:21:19 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_first_is_close(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_last_is_close(char *str)
{
	int	i;

	i = ft_strlen(str) - 2;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	ft_column_are_close(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_bis(str);
	while (str[i])
	{
		if (str[i] != '1' || str[i + j - 1] != '1')
			return (0);
		i += j + 1;
	}
	return (1);
}

int	ft_fichier_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 4))
	{
		ft_printf("not a .ber file\n");
		return (0);
	}
	return (1);
}
