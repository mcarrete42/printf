/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:23:29 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/07 22:01:51 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		type_reader(char *str, int i, va_list args, t_modifiers *flags)
{
	char *str2;
	int number_args;
	int number_flags;

	str2 = (char*)str;
	number_args = ft_arg_cunter(str2);
	number_flags = 0;

	while (str2[i] !='\0')
	{
		if (str2[i] != '%')
			ft_putchar_fd(str2[i], 1);
		else if (str2[i] == '%')
		{
			if (!ft_strchr(CONVANDFLAGS, str[i + 1]))
				break;
			while (ft_strchr(CONVANDFLAGS, str2[i + 1]))
			{
				i = i + 1;
				if(ft_strchr(FLAGS, str2[i]))
					i = flag_parser(str2, i, args, flags);
				else if (ft_strchr(CONVERSIONS, str2[i]))
					i = conversions(str2[i], i, args, flags) + 2;
			}
		}
		i++;
	}
	return (0);
}

//hay que hacer esta, es "conversions" de la otra
int	conversions(char str2_i, int i, va_list args, t_modifiers *flags)
{
	flags->i = i;
	if (str2_i == 'd' || str2_i == 'i' || str2_i == 'u')
		int_output(str2_i, i, args, flags);
	nbr_reader(str2_i, args);
	char_reader(str2_i, args);
	flags_initialiser(flags);
	return (flags->i - 1);
}


int 	nbr_reader(char str2_i, va_list args)
{
	if (str2_i == 'f')
	{
		ft_putdouble_fd(va_arg(args, double), 1);
		return (1);
	}
	if (str2_i == 'x')
	{
		ft_puthex_fd(va_arg(args, int), 1);
		return (1);
	}
	if (str2_i == 'X')
	{
		ft_puthex_upper_fd(va_arg(args, int), 1);
		return (1);
	}
	return(0);
}

int		char_reader(char str2_i, va_list args)
{
	char				*str3;
	void				*ptr;
	unsigned long int	addr;

	if (str2_i == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (str2_i == 's')
	{
		str3 = va_arg(args, char *);
		ft_putstr_fd(str3, 1);
		return (1);
	}
	else if (str2_i == 'p')  //esta mal
	{
		ptr = va_arg(args, void *);
		addr = (unsigned long int)ptr;
		ft_putptr_fd(addr, 1);
		return (1);
	}
	else if (str2_i == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return(0);
}

int		ft_arg_cunter(char *str2)
{
	char	*res;
	int		i;
	char	c;

	res = str2;
	c = '%';
	i = 0;
	while (*res)
	{
		if (*res == c)
			i++;
		res++;
	}
	return (i);
}
