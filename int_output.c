/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:24:59 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/08 19:29:36 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char *str;

	if (flags->is_width == 1)
	{
		size_t width;
		width = (size_t)flags->width;
		ft_bspace(str, width);
	}
	printf("my str de width: %s", str);
	if (str2_i == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (str2_i == 'd' || (str2_i == 'i'))
		ft_putnbr_fd(va_arg(args, int), 1);
	return (0);
}
