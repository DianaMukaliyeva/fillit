/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:14:22 by mlink             #+#    #+#             */
/*   Updated: 2019/10/28 17:14:25 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newsave;

	if (!lst || !(newlst = ft_lstnew(NULL, 0)))
		return (NULL);
	newlst = f(lst);
	newsave = newlst;
	while (lst->next)
	{
		lst = lst->next;
		newlst->next = f(lst);
		newlst = newlst->next;
	}
	return (newsave);
}
