/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:18:02 by mlink             #+#    #+#             */
/*   Updated: 2019/10/24 11:18:03 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(int n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ((n < 0) ? 1 : 0);
	n = ((n < 0) ? n *= -1 : n);
	i = ft_numlen(n) + neg;
	if (!(str = (char *)ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	while (n >= 10)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = n % 10 + '0';
	if (neg)
		str[0] = '-';
	return (str);
}
