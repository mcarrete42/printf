/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:55:32 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 20:21:18 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*elem1;

	if (!(elem1 = malloc(sizeof(t_list))))
		return (NULL);
	elem1->content = content;
	elem1->next = NULL;
	return (elem1);
}
