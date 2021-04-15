/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:28:50 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/15 17:43:26 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_checker(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->zero && flags->precision >= 0)
		flags->zero = 0;
}

void	handle_conversions(t_flags *flags, char **nbr, int len)
{
	if (flags->precision > len)
		*nbr = apply_precision(*nbr, len, flags);
	len = ft_strlen(*nbr);
	if (flags->neg)
		len++;
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	if (flags->zero && flags->neg)
		ft_putchar('-');
	while (flags->width > len  && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	if (!(flags->precision == 0 && (*nbr)[0] == '0' && (*nbr)[1] == '\0'))
	{
		if (flags->neg && !flags->zero)
			ft_putchar('-');
		ft_putstr(*nbr);
	}
	while (flags->width > len++ && flags->minus)
		ft_putchar(' ');
}

void	signed_int_conversion(va_list args, t_flags *flags)
{
	char			*nbr;
	int				len;
	int				n;
	long int		k;

	n = va_arg(args, int);
	if (n < 0)
	{
		k = n;
		k *= -1;	
		flags->neg = 1;
	}
	else
		k = n;
	nbr = ft_itoa(k);
	if (nbr[0] == '0' && nbr[1] == '\0' && flags->precision == 0)
	{
		freebird((void *)&nbr);
		nbr = ft_strdup("");
	}	
	len = ft_strlen(nbr);
	flags_checker(flags);
	handle_conversions(flags, &nbr, len);
	freebird((void *)&nbr);
}

void	unsigned_int_conversion(va_list args, t_flags *flags)
{
	char					*nbr;
	int						len;
	long unsigned int		k;

	k = va_arg(args, unsigned int);
	nbr = ft_itoa(k);
	if (nbr[0] == '0' && nbr[1] == '\0' && flags->precision == 0)
	{
		freebird((void *)&nbr);
		nbr = ft_strdup("");
	}	
	len = ft_strlen(nbr);
	flags_checker(flags);
	handle_conversions(flags, &nbr, len);
	freebird((void *)&nbr);
}

void	hex_low_conversion(va_list args, t_flags *flags)
{
	char					*nbr;
	int						len;

	nbr = hex_itoa(va_arg(args, unsigned int), "0123456789abcdef");
	if (nbr[0] == '0' && nbr[1] == '\0' && flags->precision == 0)
	{
		freebird((void *)&nbr);
		nbr = ft_strdup("");
	}	
	len = ft_strlen(nbr);
	flags_checker(flags);
	handle_conversions(flags, &nbr, len);
	freebird((void *)&nbr);
}
/*
void	hex_low_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = hex_itoa(va_arg(args, unsigned int), "01234556789abcdef");
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(nbr);
	while (flags->width > len && flags->minus)
	{
		ft_putchar(' ');
		len++;
	}
	freebird((void *)&nbr);
}
*/
void	hex_up_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = hex_itoa(va_arg(args, unsigned int), "01234556789ABCDEF");
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(nbr);
	while (flags->width > len && flags->minus)
	{
		ft_putchar(' ');
		len++;
	}
	freebird((void *)&nbr);
}
