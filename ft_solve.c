/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:59:04 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/12 15:05:06 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_map_backtrack(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_mino	*mino;

	if (list == NULL)
		return (1);
	y = 0;
	mino = (t_mino *)(list->content);
	while (y < map->size - mino->length + 1)
	{
		x = 0;
		while (x < map->size - mino->width + 1)
		{
			if (ft_mino_placer(mino, map, x, y))
			{
				if (ft_map_backtrack(map, list->next))
					return (1);
				else
					ft_mino_locker(mino, map, ft_new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*ft_map_adapter(t_list *list)
{
	t_map	*map;
	int		size;

	size = ft_highlow_sqrt(ft_lstcount(list) * 4, "high");
	map = ft_map_maker(size);
	while (ft_map_backtrack(map, list) == 0)
	{
		size++;
		ft_map_freer(map);
		map = ft_map_maker(size);
	}
	return (map);
}
