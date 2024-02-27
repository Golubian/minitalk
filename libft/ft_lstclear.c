/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:39:12 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:39:12 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_free;
	t_list	*temp;

	if (!lst)
		return ;
	to_free = *lst;
	while (to_free)
	{
		del(to_free->content);
		temp = to_free->next;
		free(to_free);
		to_free = temp;
	}
	*lst = NULL;
}
