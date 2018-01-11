/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:03:01 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/11 19:48:26 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_mino_placer(t_mino *mino, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < mino->width)
	{
		j = 0;
		while (j < mino->length)
		{
			if (mino->form[j][i] == '#' && map->map[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_mino_locker(mino, map, ft_new_point(x, y), mino->letter);
	return (1);
}

void	ft_mino_locker(t_mino *mino, t_map *map, t_point *point, char letter)
{
	int i;
	int j;

	i = 0;
	while (i < mino->width)
	{
		j = 0;
		while (j < mino->length)
		{
			if (mino->form[j][i] == '#')
				map->map[point->y + j][point->x + i] = letter;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

t_map	*ft_map_maker(int size)
{
	t_map	*map;
	int	i;
	int	j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->map = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->map[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_map_printer(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_map_freer(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->map[i]));
		i++;
	}
	ft_memdel((void **)&(map->map));
	ft_memdel((void **)&map);
}
