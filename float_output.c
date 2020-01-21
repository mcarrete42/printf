/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:43:26 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/21 20:20:44 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			float_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char			*str_flo;
	double			arg_flo;

	flags->conversion = str2_i;
	arg_flo = 0;
	arg_flo = (double)va_arg(args, double);
	printf("HOLAy arg is: %.10lf\n", arg_flo);
	str_flo = ft_doubletoa(arg_flo, flags);
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
	if (flags->precision == 0)
		while (str_flo[i] != '\0')
		{
			if (str_flo[i] == '.')
				str_flo[i] = '\0';
			i++;
		}
	return (str_flo);
}

static double				ft_ten_power(int n)
{
	long int	ten;
	int			i;

	ten = 1.0;
	i = 0;
	while (i < n - 1)
	{
		ten = ten * 10;
		i++;
	}
	return (ten);
}

char				*ft_doubletoa(long double n, t_modifiers *flags)
{
	int					in;
	long long int		dif;
	char				*ent;
	char				*dec;

	in = n;
	dif = (n - in) * ft_ten_power(flags->precision);
	if (5 <= (long int)(n * ft_ten_power(flags->precision + 1)) % 10)
		dif++;
	if ((dif) > 0)
	{
		ent = ft_itoa(in);
		dec = ft_ltoa(dif);
	}
	ent = ft_strjoin(ent, ".");
	ent = ft_strjoin(ent, dec);
	return (ent);
}
