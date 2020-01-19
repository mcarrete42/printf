/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:27:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 18:43:38 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		*str2;
	static int	i;
	int			ret;
	t_modifiers *flags;

	str2 = (char*)str;
	i = 0;
	if (!(flags = (t_modifiers*)malloc(sizeof(t_modifiers))))
		return (0);
	flags_initialiser(flags);
	flags->i = 0;
	flags->strtoformat = (char *)str;
	va_start(args, str);
	type_reader(str2, i, args, flags);
	va_end(args);
	free(flags);
	return (flags->ret_val);
}

