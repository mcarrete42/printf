/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:18:57 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/15 20:13:59 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	const char		*ptrsrc;
	char			*ptrdst;

	ptrsrc = (const char *)src;
	ptrdst = (char *)dst;
	i = 0;
	if (ptrdst == 0 && ptrsrc == 0)
		return (NULL);
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dst);
}
