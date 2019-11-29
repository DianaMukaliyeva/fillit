/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:31:05 by mlink             #+#    #+#             */
/*   Updated: 2019/10/21 11:35:56 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	negative;
	long	x;
	long	prev_x;

	x = 0;
	negative = 1;
	while (*str == ' ' || *str == '\r' || *str == '\n' || *str == '\f' \
		|| *str == '\v' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		prev_x = x;
		x = (x * 10) + (*str - '0');
		if (prev_x > x)
			return (negative == 1 ? -1 : 0);
		str++;
	}
	return ((int)x * negative);
}
