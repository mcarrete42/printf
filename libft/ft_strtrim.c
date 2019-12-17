/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:24:25 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/24 17:46:35 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_start(char const *s1, char const *set)
{
	int start;
	int i;

	start = 0;
	while (s1[start] != 0)
	{
		i = 0;
		while (s1[start] != set[i] && set[i] != 0)
			i++;
		if (set[i] == 0)
			break ;
		start++;
	}
	return (start);
}

static int			get_end(char const *s1, char const *set)
{
	int end;
	int i;

	end = ft_strlen(s1) - 1;
	while (s1[end] != 0 && end > 0)
	{
		i = 0;
		while (s1[end] != set[i] && set[i] != 0)
			i++;
		if (set[i] == 0)
			break ;
		end--;
	}
	return (end);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*s2;
	int		len_s2;

	if (s1 == NULL)
		return (NULL);
	start = (get_start(s1, set));
	end = (get_end(s1, set));
	if (start > end)
		return (ft_strdup(""));
	len_s2 = (end - start) + 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (len_s2 + 1))))
		return (NULL);
	i = 0;
	while (i < len_s2)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
