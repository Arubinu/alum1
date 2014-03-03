/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_alum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 00:41:44 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:11:56 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_all_alum_del(int rows, int c, int del, t_rows **tab);
static int		ft_all_alum_new(int rows, int c, t_rows **tab);

int				ft_all_alum(int cols, int rows, int del, int get)
{
	static int		nbr;
	static t_rows	*tab;

	if (del == -1 && tab != NULL)
	{
		free(tab);
		tab = NULL;
	}
	if (tab == NULL && (nbr = ft_all_alum_new(rows, 2, &tab)) == -2)
		return (-2);
	if (del && rows > 0 && rows <= nbr)
		ft_all_alum_del(rows, 2, del, &tab);
	if (get && !(rows > 0 && rows <= nbr))
		return (-1);
	if (get && cols <= -1)
		return ((tab + (rows - 1))->nbr);
	else if (get && cols && (tab + (rows - 1))->alum != NULL
		&& (int)ft_strlen((tab + (rows - 1))->alum) >= cols)
		return (*((tab + (rows - 1))->alum + (cols - 1)) - 1);
	return (1);
}

static void		ft_all_alum_del(int rows, int c, int del, t_rows **tab)
{
	int		i;
	char	*pos;

	pos = ft_strchr((*tab + (rows - 1))->alum, c);
	if (pos == NULL || del <= 0 || !*pos)
		return ;
	i = -1;
	(*tab + (rows - 1))->nbr -= del;
	while (++i < del && *(pos + i))
		*(pos + i) = c - 1;
	return ;
}

static int		ft_all_alum_new(int rows, int c, t_rows **tab)
{
	int				i;

	i = 0;
	if (tab != NULL && (*tab = (t_rows *)malloc(sizeof(t_rows) * rows)) != NULL)
	{
		while (++i <= rows)
		{
			(*tab + (i - 1))->nbr = ((i - 1) * 2) + 1;
			(*tab + (i - 1))->alum = ft_strcnew(c, (*tab + (i - 1))->nbr);
			if ((*tab + (i - 1))->alum == NULL)
				return (-2);
		}
	}
	else
		return (-2);
	return (rows);
}
