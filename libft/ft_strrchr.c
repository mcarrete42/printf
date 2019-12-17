/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:39:28 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/17 16:43:04 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		i--;
		s--;
	}
	return (NULL);
}
