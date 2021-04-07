/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:53:42 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/07 15:47:52 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	ft_printf("%s\n", "Bfica");
	ft_printf("%4s\n", "Bfica");
	ft_printf("%5s\n", "Bfica");
	ft_printf("%6s\n", "Bfica");
	ft_printf("%10s\n", "Bfica");
	ft_printf("%20s\n", "Bfica");
	ft_printf("__________________\n");
	ft_printf("%-s\n", "Bfica");
	ft_printf("%-4s\n", "Bfica");
	ft_printf("%-5s\n", "Bfica");
	ft_printf("%-6s\n", "Bfica");
	ft_printf("%-10s\n", "Bfica");
	ft_printf("%-20s\n", "Bfica");
	ft_printf("__________________\n");
	ft_printf("%.2s\n", "Bfica");
	ft_printf("%.4s\n", "Bfica");
	ft_printf("%6.4s\n", "Bfica");
	ft_printf("%-6.4s\n", "Bfica");
	ft_printf("%8.2s\n", "Bfica");
	ft_printf("%8.2s\n", "Bfica");
	ft_printf("__________________\n");

	return (0);
}
