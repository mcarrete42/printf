/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:40:58 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/22 18:50:05 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

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
	int				original_ret;
	int				my_ret;

	starprec = 3;
	starwidth = 7;
	ptr = &four;
	un = 10;
	e = 3.1415;
	A = 'A';
	str = "hi low";
	one = 10;
	four = 12341;


//	ft_printf("%%\n");
//	printf("%%\n");

	my_ret = ft_printf("%-10.5i", -216);
	original_ret = printf("%-10.5i", -216);
	printf("\nMy ret: %d\n Original_ret %d\n", my_ret, original_ret);


	my_ret = ft_printf("%0-10.5i", -216);
	original_ret = printf("%0-10.5i", -216);
	printf("\nMy ret: %d\n Original_ret %d\n", my_ret, original_ret);

	//ft_printf("MY FT_PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n\n", one, four);
	//printf("PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n", one, four);

	//ft_printf("MY FT_PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);
	//printf("PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);

	//ft_printf("\n MYPRINTF:\nDecimal: %2dhola\nInt: %10i\nChar: %03c\nString: %12s\nFloat: %.8f\nUnsigned Int: %u\nHex: %#x\nHEX: %#X\nPointer: %p\nPercent: %3%\n\n", four, one, A, str, e, un, four,four, ptr);
	//printf("\nPRINTF:\nDecimal: %2dhola\nInt: %10i\nChar: %03c\nString: %10s\nFloat: %.8f\nUnsigned Int: %u\nHex: %#x\nHEX: %#X\nPointer: %p\nPercent: %3%\n\n", four, one, A, str, e, un, four,four, ptr);

	//printf("\nMy STUCT:\nlen: %d\nMinus:\nZero %d\nPrecision: %d     is_precision: %d\nStar: %d\nHash: %d\nSpace: %d\nPlus: %d\nLenght: %d\nWidth: %d      is_width: %d\n", flags->len, flags->minus, flags->zero, flags->precision, flags->is_precision, flags->star, flags->hash, flags->space, flags->plus, flags->length, flags->width, flags->is_width);
}
