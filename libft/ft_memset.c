/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:13:10 by mlink             #+#    #+#             */
/*   Updated: 2019/10/21 10:13:17 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)destination;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (destination);
}
