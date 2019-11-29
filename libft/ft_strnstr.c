/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:03:40 by mlink             #+#    #+#             */
/*   Updated: 2019/10/23 12:03:44 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str2[j] != '\0' && str1[i] != '\0' && 0 < len)
	{
		if (str2[j] == str1[i + j])
			j++;
		else
		{
			i++;
			j = 0;
		}
		len--;
	}
	if (str2[j] == '\0')
		return ((char *)str1 + i);
	else
		return (NULL);
}
