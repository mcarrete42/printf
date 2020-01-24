/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:00:22 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 20:20:48 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;

	if (!new)
		return ;
	current = *lst;
	if (current)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
	else
		*lst = new;
}
