/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:14:48 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/11 19:25:31 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**faire un free_list, un free_mino, un new mino et un new_point
*/

t_list	*ft_free_list(t_list *list)
{
	t_mino	*mino;
	t_list	*next;

	while (list)
	{
		mino = (t_mino *)list->content;
		next = list->next;
		ft_free_mino(mino);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	ft_free_mino(t_mino *mino)
{
	int	i;

	i = 0;
	while (i < mino->length)
	{
		ft_memdel((void **)(&(mino->form[i])));
		i++;
	}
	ft_memdel((void **)(&(mino->form)));
	ft_memdel((void **)&mino);
}

t_point	*ft_new_point(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_mino	*ft_new_mino(char **form, int width, int length, char letter)
{
	t_mino	*mino;

	mino = ft_memalloc(sizeof(t_mino));
	mino->form = form;
	mino->length = length;
	mino->width = width;
	mino->letter = letter;
	return (mino);
}
