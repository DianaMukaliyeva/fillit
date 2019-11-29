/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:38:15 by mlink             #+#    #+#             */
/*   Updated: 2019/10/23 17:38:20 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *append, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (destination[j] && len > j)
		j++;
	while (append[i] && len > (j + i + 1))
	{
		destination[j + i] = append[i];
		i++;
	}
	if (len > j)
		destination[j + i] = '\0';
	return (ft_strlen((char *)append) + j);
}
