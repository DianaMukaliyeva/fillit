/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:32:10 by mlink             #+#    #+#             */
/*   Updated: 2019/10/21 14:32:12 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t len)
{
	unsigned char	*destination2;
	unsigned char	*source2;

	destination2 = (unsigned char *)destination;
	source2 = (unsigned char *)source;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (len > 0)
	{
		*destination2++ = *source2++;
		len--;
	}
	return (destination);
}
