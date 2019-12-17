/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:55:04 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/18 17:34:10 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				is_negative;
	unsigned long	digit;
	int				i;

	i = 0;
	is_negative = 0;
	digit = 0;
	while (ft_isspace(str[i]) && str[i] != 0)
		i++;
	is_negative = (str[i] == '-' ? -1 : 1);
	if (is_negative == -1 || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			digit = digit * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	if (i > 19 && is_negative > 0)
		return (-1);
	if (i > 19 && is_negative < 0)
		return (0);
	return ((int)digit * is_negative);
}
