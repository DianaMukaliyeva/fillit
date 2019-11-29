/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:47:00 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/11/24 18:48:23 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_tetr
{
	char			**figure;
	char			letter;
	int				height;
	struct s_tetr	*next;
}					t_tetrim;

typedef struct		s_point
{
	int				x_min;
	int				y_min;
	int				x_max;
	int				y_max;
}					t_point;

char				**ft_trim(char *buf, int *height);
void				ft_solve(t_tetrim *tetr);
size_t				ft_tetrim_size(t_tetrim *list);
t_tetrim			*ft_create_elem(char **data, char letter, int height);
int					ft_map_size(int n);
t_tetrim			*ft_create_tetrim(int fd);
void				ft_map_zeroup(char *map, char a, char b);

#endif
