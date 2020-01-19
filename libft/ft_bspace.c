/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:06:22 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/19 19:07:16 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bspace(void *s, size_t n)
{
	unsigned long	i;
	char			*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = ' ';
		i++;
	}
	ptr[i] = '\0';
}

void	ft_bzeroes(void *s, size_t n)
{
	unsigned long	i;
	char			*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '0';
		i++;
	}
	ptr[i] = '\0';
}
