/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:52:45 by mlink             #+#    #+#             */
/*   Updated: 2019/10/23 16:52:46 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t len)
{
	char	*des2;
	char	*app2;

	des2 = destination;
	app2 = (char *)append;
	while (*des2 != '\0')
		des2++;
	while (*app2 != '\0' && len > 0)
	{
		*des2++ = *app2++;
		len--;
	}
	*des2 = '\0';
	return (destination);
}
