/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:48:38 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/18 20:37:01 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (j < ft_strlen(s1))
	{
		str[j] = s1[j];
		j++;
	}
	i = j;
	j = 0;
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
