/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:52:47 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/09 19:03:15 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_p(unsigned long nb, char *base, int *i)
{
	if (nb > 15)
	{
		ft_put_p(nb / 16, base, i);
		ft_putcharv2(base[nb % 16], i);
	}
	else
		ft_putcharv2(base[nb], i);
}

void	ft_puthexa(char select, unsigned long nb, int *i)
{
	char	*base;

	if (select == 'p' || select == 'x')
		base = "0123456789abcdef";
	if (select == 'X')
		base = "0123456789ABCDEF";
	if (select == 'p')
	{
		ft_putstrv2("0x", i);
		ft_put_p(nb, base, i);
	}
	else
		ft_putnbrhexa(nb, base, i);
}
