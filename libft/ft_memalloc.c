/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:40:47 by mlink             #+#    #+#             */
/*   Updated: 2019/10/24 12:40:49 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*blank;

	if (size < 0)
		return (NULL);
	blank = malloc(size);
	if (!blank)
		return (NULL);
	ft_bzero(blank, size);
	return (blank);
}
