/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:01:49 by mlink             #+#    #+#             */
/*   Updated: 2019/11/24 18:50:20 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_create_map(char *map, int size)
{
	int		i;

	ft_strdel(&map);
	map = ft_strnew((size + 1) * size + 1);
	map = ft_memset(map, '.', (size + 1) * size);
	i = size;
	while (map[i])
	{
		map[i] = '\n';
		i = i + size + 1;
	}
	return (map);
}

static int		ft_check(char figure, t_tetrim *tetr, char *map, int *index)
{
	int	i;

	i = *index;
	if (figure == '#' && map[i] == '.')
	{
		map[i] = tetr->letter;
		i++;
		*index = i;
		return (1);
	}
	else if (figure == '.' && map[i] != '\n')
	{
		i++;
		*index = i;
		return (1);
	}
	return (0);
}

static int		ft_fit_check(t_tetrim *tetr, char *map, int size, int i)
{
	int		x;
	int		y;
	char	**figure;

	y = -1;
	x = 0;
	figure = tetr->figure;
	while (++y < tetr->height && map[i])
	{
		x = 0;
		if (y == 0 && figure[y][x] == '.')
			while (figure[y][x] == '.')
				x++;
		while (figure[y][x] && map[i])
		{
			if (ft_check(figure[y][x], tetr, map, &i))
				x++;
			else
				return (0);
		}
		i = size + 1 + i - x;
	}
	return ((y != tetr->height) ? 0 : 1);
}

static int		ft_fillit(char *map, t_tetrim *tetr, int size)
{
	int	i;

	i = 0;
	if (!tetr)
		return (1);
	while (map[i])
	{
		if (map[i] == '.')
		{
			if (ft_fit_check(tetr, map, size, i)\
				&& ft_fillit(map, tetr->next, size))
				return (1);
			else
				ft_map_zeroup(map, tetr->letter, '.');
		}
		i++;
	}
	return (0);
}

void			ft_solve(t_tetrim *tetr)
{
	// char	*requre_map = ".A...\nAAAB.\n..BBB\n.CDD.\nCCCDD\n";
	int		size;
	char	*map;

	size = ft_map_size(ft_tetrim_size(tetr));
	map = NULL;
	map = ft_create_map(map, size);
	while (!ft_fillit(map, tetr, size))
	{
		size++;
		map = ft_create_map(map, size);
	}
	if (map)
	{
		if (map[27] == 'D')
			printf("1");
		// if (strcmp(map, requre_map) == 0)
		// 	printf("1");
		else
			printf("ERROR:%s\n", map);
	}
}
