/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetromino_detect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:41:10 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/09 17:39:52 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino	*fetch_piece(char *s, char letter)
{
	
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

void	ft_read_mino(int fd)
{
	char	*buf;
	char	cur;
	int		count;
	t_list	*list;
	t_mino	mino;

	buf = ft_strnew(21);
	cur = 'A';
	while((count = read(fd, buf, 21)) >= 20)
	{

	}


}
