/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:33:19 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/24 11:32:48 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		buff;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	buff = ft_strlen(s) + 1;
	if (!(res = malloc(sizeof(char) * buff)))
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
