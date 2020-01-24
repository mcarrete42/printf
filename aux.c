/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:50:49 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/24 19:20:47 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*plus_space(int arg_int, char *str_int, t_modifiers *flags)
{
	if (arg_int >= 0 && flags->plus == 1)
		str_int = ft_strjoin("+", str_int);
	else if (arg_int >= 0 && flags->space == 1 && flags->zero == 0)
		str_int = ft_strjoin(" ", str_int);
	return (str_int);
}

char	*zero_load(char *pad_char, int padding, int arg_int, t_modifiers *flags)
{
	if (flags->zero == 0)
		ft_bspace(pad_char, padding);
	else if (flags->zero == 1)
		ft_bzeroes(pad_char, padding);
	if (arg_int >= 0 && flags->space == 1 && flags->zero == 1)
		pad_char[0] = ' ';
	if (arg_int >= 0 && flags->plus == 1 && flags->zero == 1)
	{
		if (flags->conversion == 'u')
			return (pad_char);
		else
			pad_char[0] = '+';
	}
	return (pad_char);
}
