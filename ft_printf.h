/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:13:18 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/07 13:33:15 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		conversion;
}				t_flags;

void	ft_putchar(char c);
void	ft_putstr(char *str, int width, int len, t_flags flags);
int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
void	ft_putnbr(int nb);
void	ft_putnbr_base(int nb, char *base);
int		ft_atoi(const char *nptr);
int		parse_str(char *str, va_list args);
int		ft_printf(const char *, ...);

#endif
