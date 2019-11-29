/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:37:44 by mlink             #+#    #+#             */
/*   Updated: 2019/10/28 16:37:46 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *str;
	t_list *strsave;

	str = *alst;
	while (str)
	{
		strsave = str->next;
		del((str->content), (str->content_size));
		free(str);
		str = strsave;
	}
	*alst = NULL;
}
