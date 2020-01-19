/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:26:31 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/16 19:04:45 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_hex(int n)
{
	unsigned	int		nb;
	char				*str;
	unsigned long 		rem;
	int 				i;

	nb = n;
	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	if(!(str = (char *)malloc(sizeof(char ) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	nb = n;
	while (i >= 0)
	{
		rem = nb % 16;
		str[i] = rem < 10 ? rem + '0' : rem + 'W';
		nb = nb / 16;
		i--;
	}
	return (str);
}

char	*ft_itoa_hex_upper(int n)
{
	unsigned	int		nb;
	char				*str;
	unsigned long 		rem;
	int 				i;

	nb = n;
	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	if(!(str = (char *)malloc(sizeof(char ) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	nb = n;
	while (i >= 0)
	{
		rem = nb % 16;
		str[i] = rem < 10 ? rem + '0' : rem + '7';
		nb = nb / 16;
		i--;
	}
	return (str);
}

char	*ft_ltoa_hex(unsigned long long n)
{
	unsigned long long	nb;
	char				*str;
	unsigned long 		rem;
	int 				i;

	nb = n;
	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	if(!(str = (char *)malloc(sizeof(char ) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	nb = n;
	while (i >= 0)
	{
		rem = nb % 16;
		str[i] = rem < 10 ? rem + '0' : rem + 'W';
		nb = nb / 16;
		i--;
	}
	return (str);
}
