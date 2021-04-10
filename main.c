/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:53:42 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/10 15:27:12 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
/*
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
	ft_printf("%c\n", 'f');
	ft_printf("%4c\n", 'f');
	ft_printf("__________________\n");
	ft_printf("%u\n", 22);
	ft_printf("%4.6u\n", 22);
	ft_printf("%-4.8u\n", 22);
	ft_printf("%06u\n", 22);
	printf("%u\n", 22);
	printf("%4.6u\n", 22);
	printf("%-4.8u\n", 22);
	printf("%06u\n", 22);
	ft_printf("_________________\n");
	ft_printf("%8d\n", 22);
	ft_printf("%-8.4d\n", 22);
*/
	ft_printf("%x\n", 34);
	printf("%x\n", 34);
	ft_printf("%8x\n", 34);
	printf("%8x\n", 34);
	ft_printf("%.4X\n", 34);
	printf("%.4X\n", 34);
	ft_printf("%-4X\n", 34);
	printf("%-4X\n", 34);
	return (0);
}
