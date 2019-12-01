/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:04:07 by mlink             #+#    #+#             */
/*   Updated: 2019/11/22 19:06:10 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*ft_coord_min_max(char *buf)
{
	int		i;
	t_point	*points;

	points = malloc(sizeof(t_point));
	points->x_min = 3;
	points->x_max = 0;
	points->y_min = 3;
	points->y_max = 0;
	i = -1;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i % 5) < points->x_min)
				points->x_min = i % 5;
			if ((i % 5) > points->x_max)
				points->x_max = i % 5;
			if ((i / 5) < points->y_min)
				points->y_min = i / 5;
			if ((i / 5) > points->y_max)
				points->y_max = i / 5;
		}
	}
	return (points);
}

char			**ft_trim(char *buf, int *height)
{
	t_point	*points;
	char	**new;
	int		i;

	points = ft_coord_min_max(buf);
	new = (char **)malloc(sizeof(char*) * (points->y_max - points->y_min + 1));
	if (!new)
		return (0);
	i = 0;
	while (points->y_max >= points->y_min)
	{
		new[i] = ft_strsub(buf, (points->y_min * 5 + points->x_min),\
								points->x_max - points->x_min + 1);
		i++;
		points->y_min++;
	}
	*height = i;
	ft_memdel((void**)&points);
	return (new);
}
