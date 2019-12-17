/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:00:06 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/25 20:38:38 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_word_counter(char const *s, char c)
{
	int			count_word;
	size_t		i;

	i = 0;
	count_word = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != 0)
		{
			while (s[i] != c && s[i] != 0)
				i++;
			count_word++;
		}
	}
	return (count_word);
}

void		ft_let_count(char const *s, char c, char **word_pointer)
{
	int			start;
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		start = i;
		while (s[start] == c)
			start++;
		i = start;
		while (s[i] != 0 && s[i] != c)
			i++;
		if (start != i)
		{
			word_pointer[k] = ft_substr(s, start, i - start);
			k++;
		}
	}
	word_pointer[k] = NULL;
}

char		**ft_split(char const *s, char c)
{
	char	**word_pointer;
	int		word_count;

	if (!(s))
		return (NULL);
	word_count = ft_word_counter(s, c);
	if (!(word_pointer = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	ft_let_count(s, c, word_pointer);
	return (word_pointer);
}
