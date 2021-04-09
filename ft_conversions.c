/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:59:21 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/09 14:38:20 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		counter(int n)
{
	int			i;

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

char			*ft_itoa(int n)
{
	char		*str;
	long		nbr;
	int			i;

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

int				ft_atoi(const char *nptr)
{
	int 		i;
	int 		sign;
	int 		number;

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

char		*precision_zeros(int len)
{
	int			i;
	char		*str;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[len] = '\0';
	return (str);
}
