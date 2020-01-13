/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:27:05 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/13 19:51:16 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		*str2;
	static int	i;
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
	return (0);
}

int		main()
{
	int				one;
	int				four;
	char			A;
	char			*str;
	float			e;
	unsigned int	un;
	int				*ptr;
	int				starwidth;
	int				starprec;

	starprec = 3;
	starwidth = 6;
	ptr = &four;
	un = 10;
	e = 333.1416182432565656565654;
	A = 'A';
	str = "hola que tal";
	one = 100000;
	four = 123000;
	//ft_printf("nada\n");
	//printf("%+ 5d", un);

	//ft_printf("MY FT_PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n\n", one, four);
	//printf("PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n", one, four);

	//ft_printf("MY FT_PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);
	//printf("PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);

	ft_printf("MY FT_PRINTF:\nDecimal: %*d\nInt: %4i\nChar: %c\nString: %s\nFloat: %f\nUnsigned Int: %-10u\nHex: %x\nHEX: %X\nPointer: %p\n\n", starwidth, four, one, A, str, e, un, four, four, ptr);
	printf("\nPRINTF:\nDecimal: %*d\nInt: %'i\nChar: %c\nString: %s\nFloat: %f\nUnsigned Int: %-10u\nHex: %x\nHEX: %X\nPointer: %p\n\n", starwidth, four, one, A, str, e, un, four, four, ptr);
	//printf("\nMy STUCT:\nlen: %d\nMinus:\nZero %d\nPrecision: %d     is_precision: %d\nStar: %d\nHash: %d\nSpace: %d\nPlus: %d\nLenght: %d\nWidth: %d      is_width: %d\n", flags->len, flags->minus, flags->zero, flags->precision, flags->is_precision, flags->star, flags->hash, flags->space, flags->plus, flags->length, flags->width, flags->is_width);
}

