/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:47:25 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/31 15:58:05 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		char_reader(char *str, int i, int j, va_list args)
{
	char *str2;
	char *str3;
	void *ptr;
	int addr;

	str2 = (char*)str;
	if (str2[i] == '%' && str2[j] == 'p')  //esta mal
	{
		ptr = va_arg(args, void *);
		addr = (int)ptr;
		ft_puthex_fd(addr, 1);
		return (1);
	}
	return(0);
}
int		type_reader(char *str, int i, int j, va_list args)
{
	if (char_reader(str, i, j, args) == 1)
		return (1);
	else
		return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	char *str2;
	static int i;
	static int j;

	str2 = (char*)str;
	i = 0;
	j = 1;
	va_start(args, str);
	while (str2[i] != 0)
	{
		if (type_reader(str2, i, j, args) == 1)
		{
			i++;
			j++;
		}
		else
			ft_putchar_fd(str2[i], 1);
		i++;
		j++;
	}
	va_end(args);
	return (0);
}
int		main()
{
	int four;
	int *ptr;

	ptr = &four;
	ft_printf("MY FT_PRINTF: %p\n", ptr);
	printf("PRINTF: %p\n", ptr);
}
