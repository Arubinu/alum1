/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_title.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:21:41 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_pc(char *str, int c, char *color1, char *color2);
static void		ft_print_title_one(int c, char *c1, char *c2);

int				ft_print_title(void)
{
	char	*color1;
	char	*color2;

	color1 = ft_strdup("\033[0m");
	color2 = ft_strdup("\033[38;5;75m");
	ft_putendl("\033[H\033[2J");
	ft_print_title_one('_', color1, color2);
	ft_strdel(&color1);
	ft_strdel(&color2);
	return (1);
}

static void		ft_pc(char *str, int c, char *color1, char *color2)
{
	int		i;

	if (str == NULL)
		return ;
	i = -1;
	while (*(str + (++i)))
	{
		if (color1 && *(str + i) == c && (!i || *(str + (i - 1)) != c))
			ft_putstr(color1);
		else if (color2 && *(str + i) != c && (!i || *(str + (i - 1)) == c))
			ft_putstr(color2);
		ft_putchar(*(str + i));
	}
	ft_putstr("\033[0m");
	return ;
}

static void		ft_print_title_one(int c, char *c1, char *c2)
{
	ft_pc("_____/\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\_____________", c, c1, c2);
	ft_pc("_____________________________/\\\\\\_\n", c, c1, c2);
	ft_pc(" ___/\\\\\\\\\\\\\\\\\\\\\\\\\\__\\////\\\\\\__________", c, c1, c2);
	ft_pc("____________________________/\\\\\\\\\\\\\\_\n", c, c1, c2);
	ft_pc("  __/\\\\\\/////////\\\\\\____\\/\\\\\\________________", c, c1, c2);
	ft_pc("_____________________\\/////\\\\\\_\n", c, c1, c2);
	ft_pc("   _\\/\\\\\\_______\\/\\\\\\____\\/\\\\\\_____/\\\\\\_", c, c1, c2);
	ft_pc("___/\\\\\\____/\\\\\\\\\\__/\\\\\\\\\\______\\/\\\\\\_", c, c1, c2);
	ft_putchar('\n');
	ft_pc("    _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\____\\/\\\\\\____", c, c1, c2);
	ft_pc("\\/\\\\\\___\\/\\\\\\__/\\\\\\///\\\\\\\\\\///\\\\\\___", c, c1, c2);
	ft_pc("_\\/\\\\\\_\n", c, c1, c2);
	ft_pc("     _\\/\\\\\\/////////\\\\\\____\\/\\\\\\____\\/\\\\", c, c1, c2);
	ft_pc("\\___\\/\\\\\\_\\/\\\\\\_\\//\\\\\\__\\/\\\\\\____\\/\\", c, c1, c2);
	ft_pc("\\\\_\n", c, c1, c2);
	ft_pc("      _\\/\\\\\\_______\\/\\\\\\____\\/\\\\\\____\\/\\", c, c1, c2);
	ft_pc("\\\\___\\/\\\\\\_\\/\\\\\\__\\/\\\\\\__\\/\\\\\\____\\/", c, c1, c2);
	ft_pc("\\\\\\_\n", c, c1, c2);
	ft_pc("       _\\/\\\\\\_______\\/\\\\\\__/\\\\\\\\\\\\\\\\\\_", c, c1, c2);
	ft_pc("\\//\\\\\\\\\\\\\\\\\\__\\/\\\\\\__\\/\\\\\\__\\/\\\\\\", c, c1, c2);
	ft_pc("____\\/\\\\\\_\n", c, c1, c2);
	ft_pc("        _\\///________\\///__\\/////////___\\/////////_", c, c1, c2);
	ft_pc("__\\///___\\///___\\///_____\\///__\n", c, c1, c2);
	return ;
}
