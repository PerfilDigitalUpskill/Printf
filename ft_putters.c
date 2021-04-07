/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:59:47 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/07 15:47:54 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str, int width, int len, t_flags flags)
{
	int		i;
	int		prec;

	i = 0;
	if (flags.precision != -1)
		len = flags.precision;
	prec = len;
	if (!flags.minus)
		while (width > len++)
			ft_putchar(' ');
	while (str[i] && i < prec)
		ft_putchar(str[i++]);
	if (flags.minus)
		while (width > len++)
			ft_putchar(' ');
}

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar ('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static int		check_base(char *base)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nb, char *base)
{
	int 	size;
	int		nbr[100];
	int		i;

	i = 0;
	size = ft_strlen(base);
	if (check_base(base))
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-');
		}
		while (nb)
		{
			nbr[i] = nb % size;
			nb = nb / size;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr[i]]);
	}
}
