/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:20:00 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/09 18:52:32 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list zoui, const char format, int *i)
{
	if (format == 'c')
		ft_putcharv2(va_arg(zoui, int), i);
	else if (format == 's')
		ft_putstrv2(va_arg(zoui, char *), i);
	else if (format == 'd' || format == 'i')
		ft_putnbrv2(va_arg(zoui, int), i);
	else if (format == 'u')
		ft_putnbru(va_arg(zoui, unsigned int), i);
	else if (format == 'x' || format == 'X' || format == 'p')
		ft_puthexa(format, va_arg(zoui, unsigned long), i);
	else if (format == '%')
		ft_putcharv2('%', i);
}

int	ft_printf(const char *format, ...)
{
	va_list	zoui;
	int		i;

	va_start(zoui, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(zoui, *format, &i);
		}
		else
			ft_putcharv2(*format, &i);
		format++;
	}
	va_end(zoui);
	return (i);
}
