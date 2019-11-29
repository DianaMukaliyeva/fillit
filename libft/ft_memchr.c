/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:58:43 by mlink             #+#    #+#             */
/*   Updated: 2019/10/22 13:58:45 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)arr;
	while (n--)
	{
		if (*i == ((unsigned char)c))
			return (i);
		i++;
	}
	return (NULL);
}
