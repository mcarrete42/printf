/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:00:16 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/29 23:00:37 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putdouble_fd(double n, int fd)
{
	char	c;
	int 	i;
	int 	j;
	float	dec;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	i = n;
	c = i % 10 + '0';
	write(fd, &c, 1);
	dec = (n - i) * 1000000;
	if (dec > 0)
		write(fd, ".", 1);
	if (dec > 9)
	{
		ft_putnbr_fd(dec / 10, fd);
	}
	j = dec;
	c = j % 10 + '0';
	write(fd, &c, 1);
}
