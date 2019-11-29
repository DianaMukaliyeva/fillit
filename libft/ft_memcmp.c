/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:15:09 by mlink             #+#    #+#             */
/*   Updated: 2019/10/22 17:15:10 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t len)
{
	size_t	i;
	char	*copy1;
	char	*copy2;

	copy1 = (char *)arr1;
	copy2 = (char *)arr2;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (copy1[i] != copy2[i])
			return ((unsigned char)copy1[i] - (unsigned char)copy2[i]);
		i++;
	}
	return (0);
}
