/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:27:30 by mcarrete          #+#    #+#             */
/*   Updated: 2020/01/23 20:24:07 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_node;
	t_list *my_lst;

	if (!lst)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
		return (NULL);
	my_lst = new_node;
	lst = lst->next;
	while (lst)
	{
		if (!(new_node->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&my_lst, del);
		new_node = new_node->next;
		lst = lst->next;
	}
	return (my_lst);
}
