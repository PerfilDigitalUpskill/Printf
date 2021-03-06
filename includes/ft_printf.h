/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:13:18 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/21 15:11:18 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_flags
{
	int			zero;
	int			minus;
	int			space;
	int			width;
	int			precision;
	int			neg;
	char		conversion;
}				t_flags;

void		get_flags(char *str, int *i, t_flags *flags);
void		get_width(char *str, int *i, va_list args, t_flags *flags);
void		get_precision(char *str, int *i, va_list args, t_flags *flags);
void		get_conversion(char *str, int *i, t_flags *flags);
char		*apply_space(char *nbr);

void		flags_checker(t_flags *flags);
void		handle_conversions(t_flags *flags, char **nbr, int len);
void		signed_int_conversion(va_list args, t_flags *flags);
void		unsigned_int_conversion(va_list args, t_flags *flags);
void		hex_conversion(va_list args, t_flags *flags);

void		ch_flags_checker(t_flags *flags);
void		string_conversion(va_list args, t_flags *flags);
void		char_conversion(va_list args, t_flags *flags);
void		ptr_conversion(va_list args, t_flags *flags);
void		percent_conversion(t_flags *flags);

void		freebird(void **ptr);
t_flags		init_flags(void);
char		*precision_zeros(int len);
char		*apply_precision(char *nbr, int len, t_flags *flags);

char		*ft_itoa(long int n);
char		*hex_itoa(unsigned int nb, char *tab);
char		*long_hex_itoa(unsigned long long int nb, char *base);
int			ft_atoi(const char *nptr);

int			counteroni(int n, int f);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
long int	handle_negs(int n, t_flags *flags);

int			ft_strlen(char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);

void		converter(va_list args, t_flags *flags);
int			conversion_parser(char *str, va_list args, int i);
int			parse_str(char *str, va_list args);
int			ft_printf(const char *format, ...);

#endif
