/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:26:14 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/27 21:26:26 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_super_atoi(char *str)
{
	int is_negative;
	int digit;
	int i;

	i = 0;
	is_negative = 1;
	digit = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ') && str[i] != '\0')
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			is_negative = is_negative * (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			digit = digit * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (digit * is_negative);
}
