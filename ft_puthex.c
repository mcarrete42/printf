/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:01:24 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/29 23:15:07 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex_fd(int n, int fd)
{
	long int	nb;
	char		c;
	long int rem;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 15)
		ft_puthex_fd(nb / 16, fd);
	rem = nb % 16;
	c = rem < 10 ? (char)rem + '0' : (char)rem + 'W';
	write(fd, &c, 1);
}

void	ft_puthex_upper_fd(int n, int fd)
{
	long int	nb;
	char		c;
	long int rem;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 15)
		ft_puthex_fd(nb / 16, fd);
	rem = nb % 16;
	c = rem < 10 ? (char)rem + '0' : (char)rem + '7';
	write(fd, &c, 1);
}
