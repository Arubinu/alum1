/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:04:04 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_print_alum_one(int nbr, int c, int max, int separator);
static int		ft_print_alum_two(int cols, int rows, int line);

void			ft_print_alum(int c, int max)
{
	int				i;
	int				nbr;
	int				scout;

	i = -1;
	nbr = 1;
	scout = (max - 1) * 2 + 1;
	while (++i < max)
	{
		ft_print_alum_one(nbr, c, scout, 0);
		nbr += 2;
		ft_putchar('\n');
	}
	return ;
}

static void		ft_print_alum_one(int nbr, int c, int max, int separator)
{
	int				i;
	int				saveh;
	int				height;
	int				length;

	height = ft_print_alum_two(0, 0, -1) - 1;
	length = ft_print_alum_two(0, 0, 0);
	saveh = height;
	separator = (TERM_WIDTH / max) - length;
	length = (max - (nbr - 1)) * ((separator + length) / 2);
	while (height-- >= -1 && (i = -1))
	{
		while (++i < nbr)
		{
			if (!i)
				ft_putchar_loop(c, length + ((max - nbr) / 2 + separator / 4));
			else
				ft_putchar_loop(c, separator);
			ft_putstr("\033[48;5;214m");
			ft_print_alum_two(i + 1, ((nbr - 1) / 2) + 1, saveh - height);
			ft_putstr("\033[0m");
		}
		ft_putchar('\n');
	}
	return ;
}

static int		ft_print_alum_two(int cols, int rows, int line)
{
	char			*dup;
	static char		**alum;
	static char		**none;

	if ((dup = NULL) == NULL && alum == NULL)
	{
		dup = ft_strdup("\033[0;4;38;5;160m▒\033[0m\n \n \n \n ");
		alum = ft_strsplit(dup, '\n');
	}
	if (none == NULL)
		none = ft_strsplit("\033[0;4;38;5;239m▒\n \n \n \n \n ", '\n');
	if (line > 0 && !ft_all_alum(cols, rows, 0, 1))
	{
		ft_putstr("\033[0;48;5;239m");
		ft_putstr(*(none + line - 1));
	}
	else if (line > 0)
		ft_putstr(*(alum + line - 1));
	else if (line == -1)
		return (ft_free_return(ft_tablen(alum), &dup));
	return (ft_free_return(ft_strlen(*(alum + 1)), &dup));
}
