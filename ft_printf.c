/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:08:38 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/09 14:38:05 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		freebird(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void			get_flags(char *str, int *i, t_flags *flags)
{
	int				z;

	z = *i;
	while (str[z] && (str[z] == '0' || str[z] == '-'))
	{
		if (str[z] == '0')
			flags->zero = 1;
		if (str[z] == '-')
			flags->minus = 1;
		z++;
	}
	*i = z;
}

void			get_width(char *str, int *i, va_list args, t_flags *flags)
{
	int				z;
	int				nb;

	nb = 0;
	z = *i;
	while (str[z] && ((str[z] >= '0' && str[z] <= '9') || str[z] == '*'))
	{
		while (str[z] >= '0' && str[z] <= '9')
		{
			nb = nb * 10 + (str[z] - '0');
			z++;
		}
		if (nb != 0)
			flags->width = nb;
		if (str[z] == '*')
		{		
			flags->width = va_arg(args, int);
			z++;
		}
	}
	*i = z;
}

void			get_conversion(char *str, int *i, t_flags *flags)
{
	int			z;

	z = *i;
	if (str[z] == 'c')
		flags->conversion = 'c';
	else if (str[z] == 's')
		flags->conversion = 's';	
	else if (str[z] == 'p')
		flags->conversion = 'p';
	else if (str[z] == 'd')
		flags->conversion = 'd';
	else if (str[z] == 'i')
		flags->conversion = 'i';	
	else if (str[z] == 'u')
		flags->conversion = 'u';
	else if (str[z] == 'x')
		flags->conversion = 'x';	
	else if (str[z] == 'X')
		flags->conversion = 'X';
	else
		printf("fucked up\n");
	*i = z;
}

void			get_precision(char *str, int *i, va_list args, t_flags *flags)
{
	int			z;
	int			nb;
	
	z = *i;
	nb = 0;
	if (str[z] == '.')
	{
		z++;
		if (str[z] == '*')
			flags->precision = va_arg(args, int);
		else
		{
		   while (str[z] >= '0' && str[z] <= '9')
		   {
			nb = nb * 10 + (str[z] - '0');
			z++;
		   }
		   flags->precision = nb;
		}
	}
	*i = z;
}

t_flags			init_flags(void)
{
	t_flags			flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.conversion = '\0';
	return (flags);
}

void			string_conversion(va_list args, t_flags *flags)
{
	char	*str;
	int		len;
	int 	i;
	int		prec;

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

void			char_conversion(va_list args, t_flags *flags)
{
	unsigned char 	c;
	int				w;

	c = va_arg(args, int);
	w = flags->width;
	while (w-- > 1)
		ft_putchar(' ');
	ft_putchar(c);
}

void			flags_checker(t_flags *flags)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->zero && flags->precision >= 0)
		flags->zero = 0;
}

void			int_conversion(va_list args, t_flags *flags)
{
	char 		*nbr;
	char		*temp;
	char		*str;
	int			len;

	flags_checker(flags);
	nbr = ft_itoa(va_arg(args, int));
	len = ft_strlen(nbr);
	if (flags->precision > len)
	{
		str = precision_zeros(flags->precision - len);
		temp = ft_strjoin(str, nbr);
		freebird((void *)&nbr);
		nbr = temp;
	}
	ft_putstr(nbr);
}

void			bufferoni(va_list args, t_flags *flags)
{
	if (flags->conversion == 's')
		string_conversion(args, flags);
   if (flags->conversion == 'c')
   		char_conversion(args, flags);
   if (flags->conversion == 'd' || flags->conversion == 'i')
	   int_conversion(args, flags);
}

int				conversion_parser(char *str, va_list args, int i)
{
	t_flags		flags;

	flags  = init_flags();
	i += 1;
	get_flags(str, &i, &flags);
	get_width(str, &i, args, &flags);
	get_precision(str, &i, args, &flags);
	get_conversion(str, &i, &flags);
	bufferoni(args, &flags);
/*
	printf("zero is %d, minus is %d, width is %d, precision is %d, conversion is %c\n", flags.zero, flags.minus, flags.width, flags.precision, flags.conversion); 
*/
	return (i);	
}

int				parse_str(char *str, va_list args)
{
	int				i;

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

int				ft_printf(const char *format, ...)
{
	va_list 		args;
	int				char_counter;
	char			*str;

	va_start(args, format);
	str = ft_strdup(format);
	char_counter = parse_str(str, args);	
	va_end(args);
	free((char *)str);
/*
	printf("printed %d chars", char_counter);
*/
	return (char_counter);
}
