/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:43:26 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 18:42:22 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			float_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char			*str_flo;
	long double			arg_flo;

	flags->conversion = str2_i;
	arg_flo = 0;
	arg_flo = (long double)va_arg(args, double);
	//printf("my arg is: %Lf\n", arg_flo);
	str_flo = ft_doubletoa(arg_flo);
	calculate_lenghts(str_flo, flags);
	/*
	printf("my str_flo: %s\n", str_flo);
	printf("is_precision: %d\n", flags->is_precision);
	printf("precision: %d\n", flags->precision);
	printf("float_dec: %d\n", flags->float_dec);
	printf("float_non_dec: %d\n", flags->float_non_dec); */
	if (flags->is_precision == 1 && flags->float_dec > 0)
		str_flo = float_precision(str_flo, args, flags);
	if (flags->is_precision == 0 && flags->float_dec > 6) // no se ha especificado asiq se usa 6 x defcto
		str_flo = round_and_break(str_flo, flags->float_non_dec + 6);
	if (flags->width > ft_strlen(str_flo))
		str_flo = is_width(arg_flo, str_flo, args, flags);
	ft_putstr_fd(str_flo, 1);
	flags->ret_val = flags->ret_val + ft_strlen(str_flo);

	free(str_flo);
	return (0);
}

char		*float_precision(char *str_flo, va_list args, t_modifiers *flags)
{
	int		i;
	int		i_break;
	i_break = flags->float_non_dec + flags->precision;
	if (flags->precision == 0) //se ha espicificado que es 0
		while (str_flo[i] != '\0')
		{
			if (str_flo[i] == '.')
				str_flo[i] = '\0';
			i++;
		}
	else if (flags->precision > 0)
		str_flo = round_and_break(str_flo, i_break);
	return (str_flo);
}

void		calculate_lenghts(char *str_flo, t_modifiers *flags)
{
	int		decimal_i;
	int		non_decimal;
	int		i;

	decimal_i = 0;
	non_decimal = 0;
	i = 0;
	while (str_flo[i] != '\0')
	{
		if (str_flo[i] == '.')
		{
			i++;
			while (str_flo[i] != '\0')
			{
				decimal_i++;
				i++;
			}
		}
		non_decimal++;
		i++;
	}
	non_decimal--;
	flags->float_dec = decimal_i;
	flags->float_non_dec = non_decimal;
}

char		*round_and_break(char *str_flo, int i)
{
	if(str_flo[i] >= '0' && str_flo[i] <= '5' &&
		 str_flo[i + 1] > '5' && str_flo[i + 1] <= '9')
		str_flo[i] = str_flo[i] + 1;
	str_flo[i + 1] = '\0';
	return (str_flo);
}
