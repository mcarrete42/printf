/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:27:18 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/21 20:16:41 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len_calc(size_t nb)
{
	int i;

	i = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_reverse(char *c, int buff)
{
	int		i;
	int		j;
	char	aux;

	j = buff - 2;
	i = (c[0] == '-' ? 1 : 0);
	while (i < (buff / 2))
	{
		aux = c[i];
		c[i] = c[j];
		c[j] = aux;
		i++;
		j--;
	}
	return (c);
}

char				*ft_itoa(int n)
{
	char			*c;
	int				buff;
	int				is_negative;
	unsigned int	nb;
	int				i;

	is_negative = (n < 0 ? -1 : 1);
	nb = (is_negative == -1 ? -n : n);
	buff = (n < 0 ? ft_len_calc(nb) + 2 : ft_len_calc(nb) + 1);
	if (!(c = (char *)malloc(sizeof(char) * buff)))
		return (NULL);
	if (is_negative == -1)
		c[0] = '-';
	i = (is_negative == -1 ? 1 : 0);
	while (nb > 9)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	c[i++] = nb % 10 + '0';
	c[i] = '\0';
	ft_reverse(c, buff);
	return (c);
}

char				*ft_ltoa(long long int n)
{
	char				*c;
	int					buff;
	int					is_negative;
	long long int		nb;
	int					i;

	is_negative = (n < 0 ? -1 : 1);
	nb = (is_negative == -1 ? -n : n);
	buff = (n < 0 ? ft_len_calc(nb) + 2 : ft_len_calc(nb) + 1);
	if (!(c = (char *)malloc(sizeof(char) * buff)))
		return (NULL);
	if (is_negative == -1)
		c[0] = '-';
	i = (is_negative == -1 ? 1 : 0);
	while (nb > 9)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	c[i++] = nb % 10 + '0';
	c[i] = '\0';
	ft_reverse(c, buff);
	return (c);
}
