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
		while (++j < len)
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
	if (!figure)
		return (0);
	if (!ft_check_neighbors(figure, height, 0))
		return (0);
	ft_tetrim_push_back(tetr, figure, height);
	return (1);
}

char	*get_tetr(int i)
{
	char	*t[] = {".#..\n###.\n....\n....\n\n",\
	 "..#.\n.###\n....\n....\n\n",\
	  "....\n.#..\n###.\n....\n\n",\
	   "....\n..#.\n.###\n....\n\n",\
	    "....\n....\n.#..\n###.\n\n",\
		"....\n....\n..#.\n.###\n\n"};

	return (t[i]);
}

char	*get_last_tetr(int i)
{
	char	*t[] = {"##..\n.##.\n....\n....\n",\
	 ".##.\n..##\n....\n....\n",\
	  "....\n##..\n.##.\n....\n",\
	   "....\n.##.\n..##\n....\n",\
	    "....\n....\n##..\n.##.\n",\
		"....\n....\n.##.\n..##\n"};

	return (t[i]);
}

void	tetr_del(t_tetrim **alst)
{
	t_tetrim *head;
	t_tetrim *strsave;
	char	**figure;
	int	height;

	head = *alst;
	while (head)
	{
		figure = head->figure;
		height = head->height;
		strsave = head->next;
		free(head);
		head = strsave;
		while (--height >= 0)
			free(figure[height]);
		free(figure);
	}
	*alst = NULL;
}

int	ft_create_tetrim(void)
{
	t_tetrim	*tetr;
	char		*t1;
	char		*t2;
	char		*t3;
	char		*t4;
	
	tetr = NULL;
	for (int t = 0; t < 1000; t++)
	{
		for (int i = 0; i < 6; i++)
		{
			t1 = get_tetr(i);
			for (int j = 0; j < 6; j++)
			{
				t2 = get_tetr(i);
				for (int k = 0; k < 6; k++)
				{
					t3 = get_tetr(i);
					for (int l = 0; l < 6; l++)
					{
						t4 = get_last_tetr(i);
						if (!(ft_validate(t1, strlen(t1))) || !ft_get_tetrim(&tetr, t1))
							printf("t1 is invalid\n");
						if (!(ft_validate(t2, strlen(t2))) || !ft_get_tetrim(&tetr, t2))
							printf("t2 is invalid\n");
						if (!(ft_validate(t3, strlen(t3))) || !ft_get_tetrim(&tetr, t3))
							printf("t3 is invalid\n");
						if (!(ft_validate(t4, strlen(t4))) || !ft_get_tetrim(&tetr, t4))
							printf("t4 is invalid\n%s\n", t4);
						ft_solve(tetr);
						tetr_del(&tetr);
						tetr = NULL;
					}
				}
			}
		}
	}
	return (1);
}

