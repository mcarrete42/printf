/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:40:58 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 21:38:22 by mcarrete         ###   ########.fr       */
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
	e = 333.1416182432565656565654;
	A = 'A';
	str = "hola";
	one = 10;
	four = 12341;


//	ft_printf("%%\n");
//	printf("%%\n");

	my_ret = ft_printf("%%", four);
	original_ret = printf("%%");
	printf("My ret is: %d\nOriginal_ret %d\n", my_ret, original_ret);


	//ft_printf("MY FT_PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n\n", one, four);
	//printf("PRINTF:\nThis is my first int: %d\nAnd this is my second int: %d\n", one, four);

	//ft_printf("MY FT_PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);
	//printf("PRINTF:\nThis is my int: %d\nAnd this is my char: %c\n\n", one, A);

	//ft_printf("\nPRINTF:\nDecimal: %2dhola\nInt: %4i\nChar: %03c\nString: %-08s\nFloat: %.2f\nUnsigned Int: %u\nHex: %#x\nHEX: %#X\nPointer: %p\nPercent: %3%\n\n", four, one, A, str, e, un, four,four, ptr);
	//printf("\nPRINTF:\nDecimal: %2dhola\nInt: %4i\nChar: %03c\nString: %-08s\nFloat: %.2f\nUnsigned Int: %u\nHex: %#x\nHEX: %#X\nPointer: %p\nPercent: %3%\n\n", four, one, A, str, e, un, four,four, ptr);

	//printf("\nMy STUCT:\nlen: %d\nMinus:\nZero %d\nPrecision: %d     is_precision: %d\nStar: %d\nHash: %d\nSpace: %d\nPlus: %d\nLenght: %d\nWidth: %d      is_width: %d\n", flags->len, flags->minus, flags->zero, flags->precision, flags->is_precision, flags->star, flags->hash, flags->space, flags->plus, flags->length, flags->width, flags->is_width);
}
