/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:00:06 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/19 20:29:09 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	ft_bzero(str, len + 1);
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
