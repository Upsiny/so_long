/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:40:50 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/11 16:50:27 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharv2(int c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstrv2(char *str, int *i)
{
	size_t	j;

	if (!str)
		ft_putstrv2("(null)", i);
	else
	{
		j = -1;
		while (str[++j])
			ft_putcharv2(str[j], i);
	}
}

void	ft_putnbrv2(int nb, int *i)
{
	if (nb == -2147483648)
	{
		ft_putcharv2('-', i);
		ft_putcharv2('2', i);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putcharv2('-', i);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbrv2(nb / 10, i);
		ft_putcharv2((nb % 10) + '0', i);
	}
	else
		ft_putcharv2(nb + '0', i);
}

void	ft_putnbru(unsigned long nb, int *i)
{
	if (nb > 9)
	{
		ft_putnbru(nb / 10, i);
		ft_putcharv2((nb % 10) + '0', i);
	}
	else
		ft_putcharv2(nb + '0', i);
}

void	ft_putnbrhexa(unsigned int nb, char *base, int *i)
{
	if (nb > 15)
	{
		ft_putnbrhexa(nb / 16, base, i);
		ft_putcharv2(base[nb % 16], i);
	}
	else
		ft_putcharv2(base[nb], i);
}
