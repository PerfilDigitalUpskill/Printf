/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:08:38 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/20 17:31:36 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converter(va_list args, t_flags *flags)
{
	if (flags->conversion == 's')
		string_conversion(args, flags);
	if (flags->conversion == 'c')
		char_conversion(args, flags);
	if (flags->conversion == 'd' || flags->conversion == 'i')
		signed_int_conversion(args, flags);
	if (flags->conversion == 'u')
		unsigned_int_conversion(args, flags);
	if (flags->conversion == 'x' || flags->conversion == 'X')
		hex_conversion(args, flags);
	if (flags->conversion == 'p')
		ptr_conversion(args, flags);
	if (flags->conversion == '%')
		percent_conversion(flags);
}

int	conversion_parser(char *str, va_list args, int i)
{
	t_flags		flags;

	flags = init_flags();
	i += 1;
	get_flags(str, &i, &flags);
	get_width(str, &i, args, &flags);
	get_precision(str, &i, args, &flags);
	get_conversion(str, &i, &flags);
	converter(args, &flags);
	return (i);
}

int	parse_str(char *str, va_list args)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i = conversion_parser(str, args, i);
		else
			ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;

	counteroni(0, 0);
	va_start(args, format);
	str = ft_strdup(format);
	parse_str(str, args);
	va_end(args);
	free((char *)str);
	return (counteroni(0, 1));
}
