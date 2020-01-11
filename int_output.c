/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:24:59 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/11 13:55:45 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char *str_int;
	int padding_int;
	char *padding_char;
	char *str_join;

	str_int = ft_itoa(va_arg(args, int));
	if (flags->width > ft_strlen(str_int))
	{
		padding_int = flags->width - ft_strlen(str_int);
		if(!(padding_char = malloc(sizeof(char) * padding_int)))
			return(0);
		if (flags->zero == 0)
			ft_bspace(padding_char, padding_int);
		if (flags->zero == 1)
			ft_bzeroes(padding_char, padding_int);
		str_join = ft_strjoin(padding_char, str_int);
		ft_putstr_fd(str_join, 1);
	}
	else
		ft_putstr_fd(str_int, 1);
	return (0);
}

/*
para el unsigned int:
	if (str2_i == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
*/
