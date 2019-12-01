/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:17:40 by mlink             #+#    #+#             */
/*   Updated: 2019/11/27 16:53:36 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_tetrim_push_back(t_tetrim **begin_list, char **data, int height)
{
	t_tetrim	*list;
	char		letter;

	if (*begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		letter = list->letter + 1;
		list->next = ft_create_elem(data, letter, height);
	}
	else
		*begin_list = ft_create_elem(data, 'A', height);
}

static int	ft_check_neighbors(char **str, int height, int amount)
{
	int i;
	int j;
	int	len;

	i = -1;
	j = 0;
	while (++i < height)
	{
		len = ft_strlen(str[i]);
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '#')
			{
				if (j - 1 >= 0 && (str[i][j - 1] == '#'))
					amount++;
				if (j + 1 < len && (str[i][j + 1] == '#'))
					amount++;
				if (i + 1 < height && (str[i + 1][j] == '#'))
					amount++;
				if (i - 1 >= 0 && (str[i - 1][j] == '#'))
					amount++;
			}
		}
	}
	return ((amount == 6 || amount == 8) ? 1 : 0);
}

static int	ft_validate(char *buf, int len)
{
	int	i;
	int	amount_tag;

	i = -1;
	amount_tag = 0;
	if (len == 20 && buf[len] != '\0')
		return (0);
	if (len == 21 && buf[20] != '\n')
		return (0);
	while (++i < 20)
	{
		if (i % 5 == 4)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else
		{
			if (buf[i] == '#')
				amount_tag++;
			else if (buf[i] != '.')
				return (0);
		}
	}
	return ((amount_tag != 4) ? 0 : 1);
}

static int	ft_get_tetrim(t_tetrim **tetr, char *buf)
{
	int		height;
	char	**figure;

	height = 0;
	figure = ft_trim(buf, &height);
	if (!ft_check_neighbors(figure, height, 0))
		return (0);
	ft_tetrim_push_back(tetr, figure, height);
	return (1);
}

t_tetrim	*ft_create_tetrim(int fd)
{
	char		buf[22];
	int			ret;
	int			amount;
	t_tetrim	*tetr;
	int			flag;

	flag = 1;
	amount = 0;
	tetr = NULL;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (ret == 20)
			flag = 1;
		else if (ret == 21)
			flag = 0;
		buf[ret] = '\0';
		if (!(ft_validate(buf, ret)) || !ft_get_tetrim(&tetr, buf))
			return (NULL);
		amount++;
	}
	if (flag == 0 || ret != 0 || amount > 26 || amount < 1)
		return (NULL);
	return (tetr);
}
