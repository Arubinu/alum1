/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_easter_eggs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 09:36:37 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:52:17 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_print_easter_eggs_separator(int d, int w, char *s, int ch);
static void		ft_print_easter_eggs_str(int decal, int width, int c, char *s);

void			ft_print_easter_eggs(int decal, int width, int c, int error)
{
	if (error == 4)
	{
		ft_print_easter_eggs_str(decal, width, c, "");
		ft_print_easter_eggs_str(decal, width, c, "");
		ft_print_easter_eggs_str(decal, width, c, "! ! !  YEAY  ! ! !");
		ft_print_easter_eggs_str(decal, width, c, "");
	}
	return ;
}

static void		ft_print_easter_eggs_separator(int d, int w, char *s, int ch)
{
	if (!ch && s != NULL)
	{
		ft_putchar_loop(' ', d);
		ft_putchar('_');
		if (*s == '-')
			ft_putstr("\033[1m");
	}
	else if (ch > 0 && s != NULL)
	{
		if (*s == '-')
			ft_putstr("\033[0m");
		ft_putchar('_');
	}
	else
	{
		ft_putchar_loop(' ', d);
		ft_putchar_loop('_', w - d);
		ft_putchar('\n');
	}
	return ;
}

static void		ft_print_easter_eggs_str(int decal, int width, int c, char *s)
{
	int		i;
	int		diff;
	int		length;

	ft_print_easter_eggs_separator(decal, width, s, 0);
	width -= decal + 2;
	length = ft_strlen(s);
	i = -1;
	while (*(s + (++i)))
	{
		if (!ft_isprint(*(s + i)) && ++i)
			--length;
	}
	diff = (width - length) / 2;
	ft_putchar_loop(c, diff);
	ft_putstr(s);
	diff = width - (diff + length);
	ft_putchar_loop(c, diff);
	ft_print_easter_eggs_separator(decal, width, s, 1);
	ft_putchar('\n');
	return ;
}
