/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_alum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:34:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_end_alum_print(void);
static int		ft_end_alum_new(char **entry, char *bin);

int				ft_end_alum(char **entry, char *bin, int error)
{
	int		i;
	int		nbr;
	int		count;

	i = ft_reset_alum(NULL, 0, 0) + 1;
	count = 0;
	while (--i > 0)
	{
		nbr = ft_all_alum(-1, i, 0, 1);
		count += (nbr >= 0) ? nbr : 0;
	}
	if (count > 0)
	{
		ft_print_alum(' ', ft_reset_alum(NULL, 0, 0));
		ft_print_prompt(entry, error);
	}
	else
		return (ft_end_alum_new(entry, bin));
	return (1);
}

static int		ft_end_alum_new(char **entry, char *bin)
{
	char	*tmp;

	ft_strdel(entry);
	while (42)
	{
		ft_print_title();
		ft_print_notice(TITLE_DECAL, TERM_WIDTH, 0, bin);
		if (*entry != NULL)
		{
			if (!ft_strcmp(*entry, "exit"))
				break ;
			else if (!ft_strncmp(*entry, "new", 2))
			{
				tmp = ft_strdup(*entry);
				if (!ft_reset_alum(&tmp, 1, 0) && !ft_calc_alum(NULL, -1))
					return (-3);
			}
		}
		ft_end_alum_print();
		ft_print_prompt(NULL, 0);
		ft_strdel(entry);
		ft_get_next_line(STDIN_FILENO, entry);
	}
	return (ft_free_return(0, entry));
}

static void		ft_end_alum_print(void)
{
	ft_putchar('\n');
	ft_putchar_loop(' ', ((TITLE_DECAL + TERM_WIDTH) - 36) / 2);
	ft_putstr("Bravo, le joueur ");
	ft_putchar(ft_calc_alum(NULL, 1) + '1');
	ft_putendl(" ressort gagnant !\n");
	ft_putchar_loop(' ', ((TITLE_DECAL + TERM_WIDTH) - 44) / 2);
	ft_putendl("Voulez-vous rejouer (sinon écrivez \"exit\") ?");
	ft_putchar_loop(' ', ((TITLE_DECAL + TERM_WIDTH) - 57) / 2);
	ft_putendl("Pour ce faire, écrivez \"new\", suivi d'un nombre de rangé.\n");
	return ;
}
