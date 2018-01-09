/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:23:48 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/09 17:50:49 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_map
{

}				t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_mino
{
	char	**pos;
	int		height;
	int		length;
	char	count;
}				t_mino;

void			ft_file_reader();
void			ft_printer();
void			ft_tetromino_detect();

#endif
