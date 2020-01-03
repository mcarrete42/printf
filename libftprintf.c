/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:27:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/02 19:58:46 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	int one;
	int four;
	char A;
	char *str;
	float e;
	unsigned int un;
	int *ptr;

	ptr = &four;
	un = 23;
	e = 333.1416182434;
	A = 'A';
	str = "hola que tal";
	one = -2147483648;
	four = 10;
	//ft_printf("%d\n", one);
	//printf("a");

	//ft_printf("MY FT_PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n\n", one, four);
	//printf("PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n", one, four);

	//ft_printf("MY FT_PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);
	//printf("PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);

	ft_printf("MY FT_PRINTF:\nDecimal: %-d\nInt: %i\nChar: %c\nString: %s\nFloat: %f\nUnsigned Int: %u\nHex: %x\nHEX: %X\nPointer: %p\n\n", four, one, A, str, e, un, four, four, ptr);
	printf("PRINTF:\nDecimal: %d\nInt: %i\nChar: %c\nString: %s\nFloat: %f\nUnsigned Int: %u\nHex: %x\nHEX: %X\nPointer: %p\n\n", four, one, A, str, e, un, four, four, ptr);
}
