/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:59:47 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/21 12:44:32 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counteroni(int n, int f)
{
	static int	biff;

	if (f)
		biff += n;
	if (!f)
		biff = 0;
	return (biff);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	counteroni(1, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
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

long int	handle_negs(int n, t_flags *flags)
{
	long int	k;

	if (n < 0)
	{
		k = n;
		k *= -1;
		flags->neg = 1;
	}
	else
		k = n;
	return (k);
}
