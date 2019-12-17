/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:18:57 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/17 11:08:58 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	const char		*ptrsrc;
	char			*ptrdst;

	ptrsrc = src;
	ptrdst = dst;
	i = 0;
	if (ptrdst == 0 && ptrsrc == 0)
		return (NULL);
	if (ptrdst < ptrsrc)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		ptrdst[len] = ptrsrc[len];
	return (dst);
}
