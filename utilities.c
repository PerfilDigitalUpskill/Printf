/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:42:12 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/12 14:39:27 by malmeida         ###   ########.fr       */
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

char	*precision_zeros(int len)
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

char	*apply_precision(char *nbr, int len, t_flags *flags)
{
	char		*str;
	char		*temp;

	str = precision_zeros(flags->precision - len);
	temp = ft_strjoin(str, nbr);
	freebird((void *)&nbr);
	freebird((void *)&str);
	nbr = temp;
	return (nbr);
}
