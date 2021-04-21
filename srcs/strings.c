/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:14:21 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/21 13:17:39 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	ptr = (char *)malloc(sizeof(*ptr) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		z;

	if (!s1 || !s2)
		return (0);
	i = (ft_strlen((char *)s1));
	z = (ft_strlen((char *)s2));
	str = (char *)malloc(sizeof(char) * (z + i + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	z = 0;
	while (s2[z])
	{
		str[i++] = s2[z++];
	}
	str[i] = '\0';
	return (str);
}

char	*apply_plus(char *nbr)
{
	char *temp;

	temp = ft_strjoin("+", nbr);
	freebird((void *)&nbr);
	nbr = temp;
	return (nbr);
}
