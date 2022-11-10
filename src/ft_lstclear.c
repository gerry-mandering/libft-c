/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:17:00 by minseok2          #+#    #+#             */
/*   Updated: 2022/07/15 12:28:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	copy = *lst;
	while (copy)
	{
		del(copy->content);
		temp = copy->next;
		free(copy);
		copy = temp;
	}
	*lst = NULL;
}
