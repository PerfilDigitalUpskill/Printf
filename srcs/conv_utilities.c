/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:59:21 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/19 15:36:46 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(long int n)
{
	int		i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(long int n)
{
	char	*str;
	long	nbr;
	int		i;

	nbr = n;
	i = counter(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (0);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*hex_itoa(unsigned int nb, char *tab)
{
	char				*str;
	int					size;
	unsigned int		temp;
	int					base;

	base = 16;
	size = 0;
	temp = nb;
	while (temp /= base)
		size++;
	size += 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size)
	{
		str[size - 1] = tab[ft_abs(nb % base)];
		size--;
		nb /= base;
	}
	return (str);
}


char	*long_hex_itoa(unsigned long long int nb, char *tab)
{
	char						*str;
	int							size;
	unsigned long long int		temp;
	int							base;

	base = 16;
	size = 0;
	temp = nb;
	while (temp /= base)
		size++;
	size += 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size)
	{
		str[size - 1] = tab[ft_abs(nb % base)];
		size--;
		nb /= base;
	}
	return (str);
}
/*
char	*long_hex_itoa(unsigned long long int nb, char *base)
{
	int		size;
	int		nbr[50];
	int		i;
	int		j;
	char	*str;

	i = 0;
	size = ft_strlen(base);
	while (nb)
	{
		nbr[i] = nb % size;
		nb = nb / size;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (--i >= 0)
		str[j++] = base[nbr[i]];
	str[j] = '\0';
	return (str);
}
*/
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		number;

	i = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32)))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	number = 0;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number *= 10;
		number += nptr[i] - '0';
		i++;
	}
	return (number * sign);
}
