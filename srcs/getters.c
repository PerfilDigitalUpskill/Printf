/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:10:14 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/21 16:06:00 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char *str, int *i, t_flags *flags)
{
	int		z;

	z = *i;
	while (str[z] && (str[z] == '0' || str[z] == '-' || str[z] == ' '))
	{
		if (str[z] == '0')
			flags->zero = 1;
		if (str[z] == '-')
			flags->minus = 1;
		if (str[z] == ' ')
			flags->space = 1;
		z++;
	}
	*i = z;
}

void	get_width(char *str, int *i, va_list args, t_flags *flags)
{
	int		z;
	int		nb;

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

void	get_precision(char *str, int *i, va_list args, t_flags *flags)
{
	int		z;
	int		nb;

	z = *i;
	nb = 0;
	if (str[z] == '.')
	{
		z++;
		if (str[z] == '*')
		{
			flags->precision = va_arg(args, int);
			z++;
		}
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

void	get_conversion(char *str, int *i, t_flags *flags)
{
	int		z;

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
	else if (str[z] == '%')
		flags->conversion = '%';
	*i = z;
}

char	*apply_space(char *nbr)
{
	char	*temp;

	temp = ft_strjoin(" ", nbr);
	freebird((void *)&nbr);
	nbr = temp;
	return (nbr);
}
