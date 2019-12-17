/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:27:31 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/22 19:49:53 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
