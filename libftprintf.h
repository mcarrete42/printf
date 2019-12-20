/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:12:10 by mcarrete          #+#    #+#             */
/*   Updated: 2019/12/19 21:21:56 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
#include <stdarg.h>
# include "libft/libft.h"

//int ft_printf(const char *str, ...);

int ft_printf(char *str, ...);


#endif
