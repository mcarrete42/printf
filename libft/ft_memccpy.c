/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:18:57 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/14 19:53:03 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			cchar;
	unsigned char			*ptrsrc;
	unsigned char			*ptrdst;

	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	cchar = (unsigned char)c;
	if (ptrdst != NULL || ptrsrc != NULL)
	{
		while (*ptrsrc != cchar && n > 0)
		{
			*ptrdst = *ptrsrc;
			ptrdst++;
			ptrsrc++;
			n--;
		}
	}
	if (*ptrsrc == cchar)
	{
		*ptrdst = *ptrsrc;
		ptrdst++;
		return (ptrdst);
	}
	return (NULL);
}
