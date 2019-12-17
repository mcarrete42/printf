/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:47:08 by mcarrete          #+#    #+#             */
/*   Updated: 2019/11/27 20:28:10 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp_next;
	t_list		*temp;

	if (*lst == NULL || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
}
