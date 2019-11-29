/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:08 by mlink             #+#    #+#             */
/*   Updated: 2019/10/22 17:32:10 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0' && str2[j] == str1[i + j])
			j++;
		if (str2[j] == '\0')
			return ((char *)str1 + i);
		i++;
	}
	return (NULL);
}
