/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daogawa <daogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:51:27 by daogawa           #+#    #+#             */
/*   Updated: 2025/10/23 23:07:58 by daogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*node;
	void	*node_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	res_lst = NULL;
	while (lst)
	{
		node_content = f(lst->content);
		node = ft_lstnew(node_content);
		if (node == NULL)
		{
			if (del)
				del(node_content);
			ft_lstclear(&res_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&res_lst, node);
		lst = lst->next;
	}
	return (res_lst);
}
