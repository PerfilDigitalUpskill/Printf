/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:13:18 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/12 14:37:23 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		conversion;
}				t_flags;

void	get_flags(char *str, int *i, t_flags *flags);
void	get_width(char *str, int *i, va_list args, t_flags *flags);
void	get_precision(char *str, int *i, va_list args, t_flags *flags);
void	get_conversion(char *str, int *i, t_flags *flags);

void	flags_checker(t_flags *flags);
void	signed_int_conversion(va_list args, t_flags *flags);
void	unsigned_int_conversion(va_list args, t_flags *flags);
void	hex_low_conversion(va_list args, t_flags *flags);
void	hex_up_conversion(va_list args, t_flags *flags);

void	string_conversion(va_list args, t_flags *flags);
void	char_conversion(va_list args, t_flags *flags);

void	freebird(void **ptr);
t_flags	init_flags(void);
char	*precision_zeros(int len);
char	*apply_precision(char *nbr, int len, t_flags *flags);

char	*ft_itoa(int n);
char	*hex_itoa(int nb, char *base);
int		ft_atoi(const char *nptr);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

void	converter(va_list args, t_flags *flags);
int		conversion_parser(char *str, va_list args, int i);
int		parse_str(char *str, va_list args);
int		ft_printf(const char *format, ...);

#endif
