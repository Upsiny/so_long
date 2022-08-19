/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:35:53 by hguillau          #+#    #+#             */
/*   Updated: 2022/07/19 09:54:08 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_putcharv2(int c, int *i);
void	ft_putstrv2(char *str, int *i);
void	ft_putnbrv2(int nb, int *i);
void	ft_putnbru(unsigned long nb, int *i);
void	ft_putnbrhexa(unsigned int nb, char *base, int *i);
void	ft_puthexa(char select, unsigned long nb, int *i);
void	ft_put_p(unsigned long nb, char *base, int *i);

#endif
