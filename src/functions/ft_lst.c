/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:23:20 by jaehyuki          #+#    #+#             */
/*   Updated: 2023/01/19 20:15:46 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		puterr_exit("Get last list fail!\n");
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		puterr_exit("ADD list fail!\n");
	if (!(lst[0]))
		lst[0] = new;
	else
	{
		last = ft_lstlast(lst[0]);
		last->next = new;
		new->pre = last;
	}
}

t_list	*ft_lstnew(void	*content, int obj_type)
{
	t_list	*new;

	if (content == NULL)
		puterr_exit("Make list fail!\n");
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		puterr_exit("Allocate fail!\n");
	new->obj_type = obj_type;
	new->content = content;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}
