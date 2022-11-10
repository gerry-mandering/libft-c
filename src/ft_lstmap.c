/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:56:53 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/15 13:41:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copied_lst;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	copied_lst = ft_lstnew(f(lst -> content));
	if (copied_lst == NULL)
		return (NULL);
	lst = lst -> next;
	while (lst)
	{
		temp = ft_lstnew(f(lst -> content));
		if (temp == NULL)
		{
			if (del == NULL)
				return (NULL);
			ft_lstclear(&copied_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&copied_lst, temp);
		lst = lst -> next;
	}
	return (copied_lst);
}
