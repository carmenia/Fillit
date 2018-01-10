/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:23:48 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/10 21:30:47 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_mino
{
	char	**form;
	int		length;
	int		width;
	char	letter;
}				t_mino;

void	ft_mino_border(char *s, t_point *min, t_point *max);
t_mino	*ft_fetch_mino(char *s, char letter);
t_mino	*ft_new_mino(char **form, int height, int length, char letter);
int	ft_check_mino_self(char *s);
int	ft_check_mino_environment(char *s, int count);
t_list	*ft_read_mino(int fd);
t_list	*ft_free_list(t_list *list);
void	ft_free_mino(t_mino *mino);
t_point	*ft_new_point(int x, int y);

#endif
