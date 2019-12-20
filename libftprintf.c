/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:27:05 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/19 21:26:03 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
int		percent_counter(const char *str)
{
	int counter;
	//function to count how many argument we have, by counting
	//the amount of %. Careful, as %% is not an extra argument.
	return (counter);
}

int		type_reader(const char *str)
{
	while (*str)
	{
		//function to find first %.
		if (str + 1 == 'd')//after % is a d
			return (1);
		//after % is an i return 2 ...
}
*/


int		ft_printf(char *str, ...)
{
	va_list args;
	int i;
	int value;  //test for d
	int arg_count = percent_counter(str);
	i = 0;
	va_start(args, arg_count);
	while (i < arg_count)
	{
		value = va_arg(args, int);
	i++;
	}
	va_end(args);
	return (0);
}

int		main()
{
	ft_printf("hola %d\n", 1, 2, 3);
}
