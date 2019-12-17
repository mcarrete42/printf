/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:09:44 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/12 18:12:01 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	i;
	unsigned char	value;
	char			*ptr;

	ptr = str;
	value = c;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
	return (str);
}
