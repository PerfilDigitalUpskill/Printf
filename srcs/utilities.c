/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:42:12 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/14 19:04:36 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	freebird(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

t_flags	init_flags(void)
{
	t_flags		flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.conversion = '\0';
	return (flags);
}

char	*precision_zeros(int len, int neg)
{
	int			i;
	char		*str;

	i = 0;
	if (neg)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (neg)
	{
		str[0] = '-';
		i++;
	}
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	handle_negs(char **nbr, int	len)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(*nbr);
	freebird((void *)nbr);
	*nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return ;
	while (temp[i])
	{
		(*nbr)[i] = temp[i + 1];
		i++;
	}
	(*nbr)[i] = '\0';
	freebird((void *)&temp);
}

char	*apply_precision(char *nbr, int len, t_flags *flags)
{
	char		*str;
	char		*temp;
	int			neg;

	neg = 0;
	if (nbr[0] == '-')
		neg = 1;
	str = precision_zeros(flags->precision - len, neg);
	if (neg == 1)
		handle_negs(&nbr, len - 1);
	temp = ft_strjoin(str, nbr);
	freebird((void *)&nbr);
	freebird((void *)&str);
	nbr = temp;
	return (nbr);
}
