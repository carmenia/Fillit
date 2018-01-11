/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mino_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:11:54 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/11 20:06:39 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mino_border(char *s, t_point *min, t_point *max)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_mino	*ft_fetch_mino(char *s, char letter)
{
	t_point	*min;
	t_point	*max;
	char	**form;
	int		i;
	t_mino	*mino;

	min = ft_new_point(4, 4);
	max = ft_new_point(0,0);
	ft_mino_border(s, min, max);
	form = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		form[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(form[i], s + (min->x) + (i + min->y) * 5,
			max->x - min->x + 1);
		i++;
	}
	mino = ft_new_mino(form, max->x - min->x + 1, max->y - min->y, letter);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (mino);
}

int		ft_check_mino_self(char *s)
{
	int	i;
	int part;

	part = 0;
	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (((i + 1) < 20 && s[i + 1] == '#')
					|| ((i - 1) > 0 && s[i - 1] =='#')
					|| ((i + 5) < 20 && s[i + 5] == '#')
					|| ((i - 5) > 0 && s[i - 5] == '#'))
				part++;
		}
		i++;
	}
	if (part == 6 || part == 8)
		return (1);
	else
		return (0);
}

int		ft_check_mino_environment(char *s, int count)
{
	int	i;
	int	part;

	part = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (s[i] != '.' || s[i]!= '#')
				return (1);
			if (s[i] == '#' && ++part > 4)
				return (1);
		}
		else if (s[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && s[i] != '\n')
		return (1);
	if (ft_check_mino_self(s) != 1)
		return (1);
	return (0);
}

t_list	*ft_read_mino(int fd)
{
	char	*buf;
	char	cur;
	int		count;
	t_list	*list;
	t_mino	*mino;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while((count = read(fd, buf, 21)) >= 20)
	{
		if (ft_check_mino_environment(buf, count) !=0
				|| (mino = ft_fetch_mino(buf, cur++)) == NULL)
		{
			ft_memdel((void**)&buf);
			return (ft_free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(mino, sizeof(t_mino)));
		ft_memdel((void **)&mino);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (ft_free_list(list));
	ft_lstrev(&list);
	return (list);
}
