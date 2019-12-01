/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:16:02 by mlink             #+#    #+#             */
/*   Updated: 2019/11/24 18:50:41 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	error_input(void)
{
	write(1, "usage: fillit input_file\n", 25);
	return (1);
}

static int	error(void)
{
	write(1, "error\n", 6);
	return (2);
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


int			main(int argc, char **argv)
{
	t_tetrim	*tetr;
	int			fd;

	if (argc != 2)
		return (error_input());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !(tetr = ft_create_tetrim(fd)))
		return (error());
	ft_solve(tetr);
	tetr_del(&tetr);
	return (0);
}
