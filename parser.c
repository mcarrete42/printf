/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:29 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/30 23:58:07 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		type_reader(char *str, int i, int j, va_list args)
{
	if (int_reader(str, i, j, args) == 1)
		return (1);
	else if (nbr_reader(str, i, j, args) == 1)
		return (1);
	else if (char_reader(str, i, j, args) == 1)
		return (1);
	else
		return (0);
}

int		int_reader(char *str, int i, int j, va_list args)
{
	char *str2;

	str2 = (char*)str;
	if (str2[i] == '%' && str2[j] == 'd')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		return (1);
	}
	if (str2[i] == '%' && str2[j] == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		return (1);
	}
	if (str2[i] == '%' && str2[j] == 'u')
	{
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
		return (1);
	}
	return(0);
}

int 	nbr_reader(char *str, int i, int j, va_list args)
{
	char *str2;

	str2 = (char*)str;
	if (str2[i] == '%' && str2[j] == 'f')
	{
		ft_putdouble_fd(va_arg(args, double), 1);
		return (1);
	}
	if (str2[i] == '%' && str2[j] == 'x')
	{
		ft_puthex_fd(va_arg(args, int), 1);
		return (1);
	}
	if (str2[i] == '%' && str2[j] == 'X')
	{
		ft_puthex_upper_fd(va_arg(args, int), 1);
		return (1);
	}
	return(0);
}

int		char_reader(char *str, int i, int j, va_list args)
{
	char *str2;
	char *str3;
	void *ptr;
	int addr;

	str2 = (char*)str;
	if (str2[i] == '%' && str2[j] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}

	else if (str2[i] == '%' && str2[j] == 's')
	{
		str3 = va_arg(args, char *);
		ft_putstr_fd(str3, 1);
		return (1);
	}
	else if (str2[i] == '%' && str2[j] == 'p')  //esta mal
	{
		ptr = va_arg(args, void *);
		addr = (int)ptr;
		ft_puthex_fd(addr, 1);
		return (1);
	}
	else if (str2[i] == '%' && str2[j] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return(0);
}
