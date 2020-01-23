/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:18:46 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 17:22:41 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	string_output(char str2_i, int i, va_list args, t_modifiers *flags)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	flags->conversion = str2_i;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->is_precision == 1)
		str = string_precision(str, flags);
	if (flags->width > ft_strlen(str))
		string_flags(str, args, flags);
	else
	{
		ft_putstr_fd(str, 1);
		flags->ret_val = flags->ret_val + ft_strlen(str);
	}
}

int		string_flags(char *str, va_list args, t_modifiers *flags)
{
	char	*padding_str;
	int		padding;

	padding = flags->width - ft_strlen(str);
	if (!(padding_str = (malloc(sizeof(char) * padding))))
		return (0);
	if (flags->zero == 0)
		ft_bspace(padding_str, padding);
	else if (flags->zero == 1)
		ft_bzeroes(padding_str, padding);
	if (flags->minus == 0)
		padding_str = ft_strjoin(padding_str, str);
	else if (flags->minus == 1)
		padding_str = ft_strjoin(str, padding_str);
	ft_putstr_fd(padding_str, 1);
	flags->ret_val = flags->ret_val + ft_strlen(padding_str);
	free(padding_str);
	return (0);
}

char	*string_precision(char *str, t_modifiers *flags)
{
	char	*strdup;
	int		i;

	i = 0;
	if (flags->precision < ft_strlen(str))
	{
		if (!(strdup = (char *)malloc(sizeof(char) * flags->precision + 1)))
			return (NULL);
		while (i < flags->precision)
		{
			strdup[i] = str[i];
			i++;
		}
		strdup[i] = '\0';
	}
	else
		strdup = str;
	return (strdup);
}
