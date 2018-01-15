/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:18:40 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/15 12:47:44 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;
	char	*s;

	s = ft_strfd(argv[1]);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit sample_file\n");
		return (1);
	}
	if ((list = ft_read_mino(open(argv[1], O_RDONLY))) == NULL
			|| s[(ft_sizefd(argv[1]) - 2)] == '\n')
	{
		ft_putstr("error\n");
		return (1);
	}
	map = ft_map_adapter(list);
	ft_map_printer(map);
	ft_map_freer(map);
	ft_free_list(list);
	return (0);
}
