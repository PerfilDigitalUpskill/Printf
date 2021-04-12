/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:54:46 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/12 14:14:07 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(va_list args, t_flags *flags)
{
	char			*str;
	int				len;
	int				i;
	int				prec;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	i = 0;
	if (flags->precision != -1)
		len = flags->precision;
	prec = len;
	if (!flags->minus)
		while (flags->width > len++)
			ft_putchar(' ');
	while (str[i] && i < prec)
		ft_putchar(str[i++]);
	if (flags->minus)
		while (flags->width > len++)
			ft_putchar(' ');
}

void	char_conversion(va_list args, t_flags *flags)
{
	unsigned char	c;
	int				w;

	c = va_arg(args, int);
	w = flags->width;
	while (w-- > 1)
		ft_putchar(' ');
	ft_putchar(c);
}
