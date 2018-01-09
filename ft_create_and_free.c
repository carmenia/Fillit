/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:14:48 by carmenia          #+#    #+#             */
/*   Updated: 2018/01/09 18:25:34 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

faire un free_list, un free_mino, un new mino et un new_point

t_list	*free_list(t_list *list)
{
	t_mino	*mino;
	t_list	*next;

	while (list)
	{
		mino = (t_mino *)list->content;
		next = list->next;
		free_mino(mino);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	free_mino(t_mino *mino)
{
	int	i;

	i = 0;
	while (i < mino->length)
	{
		ft_memdel((void **)(&(mino->pos[i])));
		i++;
	}
	ft_memdel((void **)(&(mino->pos)));
	ft_memdel((void **)&mino);
}
