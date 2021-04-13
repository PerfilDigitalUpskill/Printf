/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:54:46 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/13 17:18:55 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ch_flags_checker(t_flags *flags)
{
	if (flags->precision != -1 && flags->precision < -1)
		flags->minus = 1;
}

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

	ch_flags_checker(flags);
	c = va_arg(args, int);
	w = flags->width;
	while (w-- > 1 && !flags->minus)
		ft_putchar(' ');
	ft_putchar(c);
	while (w-- > 0 && flags->minus)
		ft_putchar(' ');
}

void	ptr_conversion(va_list args, t_flags *flags)
{
	unsigned long long int	i;
	int						j;
	char					*str;
	char					*temp;

	flags_checker(flags);
	i = va_arg(args, unsigned long long int);
	str = long_hex_itoa(i, "0123456789abcdef");
	temp = ft_strjoin("0x", str);
	freebird((void *)&str);
	str = temp;
	j = ft_strlen(str);
	while (flags->width > j++ && !(flags->minus) && !(flags->zero))
		ft_putchar(' ');
	while (flags->width > j++ && flags->zero)
		ft_putchar('0');
	ft_putstr(str);
	while (flags->width > j++ && flags->minus)
		ft_putchar(' ');
}
