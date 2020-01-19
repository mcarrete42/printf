/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:29:42 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 15:23:18 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	char_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char	a;

	flags->conversion = str2_i;
	a = (unsigned char)va_arg(args, int);
	if (flags->width > 1)
		char_flags(a, args, flags);
	else
		ft_putchar_fd(a, 1);
}

void	percent_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char	a;

	flags->conversion = str2_i;
	a = str2_i;
	if (flags->width > 1)
		char_flags(a, args, flags);
	else
		ft_putchar_fd(a, 1);
}

int		char_flags(char a, va_list args, t_modifiers *flags)
{
	char	*str_char;
	int		padding;
	if (flags->conversion == 'c' || flags->conversion == '%')
		padding = flags->width - 1;
	if (!(str_char = (malloc(sizeof(char) * padding))))
		return(0);
	if (flags->zero == 0)
		ft_bspace(str_char, padding);
	else if (flags->zero == 1)
		ft_bzeroes(str_char, padding);
	if (flags->minus == 0)
	{
		ft_putstr_fd(str_char, 1);
		ft_putchar_fd(a, 1);
	}
	else if (flags->minus == 1)
	{
		ft_putchar_fd(a, 1);
		ft_putstr_fd(str_char, 1);
	}
	free(str_char);
	return (0);
}
