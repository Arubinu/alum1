/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_notice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:41:35 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		ft_print_notice_entry(int decal, int width, int error);
static int		ft_print_notice_error(int decal, int width, char *bin);
static void		ft_print_notice_separator(int d, int w, char *str, int choice);
static void		ft_print_notice_str(int decal, int width, int c, char *str);

int				ft_print_notice(int decal, int width, int error, char *bin)
{
	char	*str;

	str = NULL;
	if (error == 1)
		return (ft_print_notice_error(decal, width, bin));
	ft_print_notice_separator(decal, width, NULL, -1);
	ft_print_notice_str(decal, width, ' ', "");
	ft_print_notice_str(decal, width, ' ', "- Règle du jeu ! -");
	str = ft_strfdup(&str, "Ne pas prendre la dernière allumette ...", 1);
	ft_print_notice_str(decal, width, ' ', str);
	str = ft_strfdup(&str, "Au minimum, il y aura 4 rangées d'allumettes.", 1);
	ft_print_notice_str(decal, width, ' ', str);
	ft_print_notice_str(decal, width, ' ', "");
	ft_print_notice_str(decal, width, ' ', "- Comment on y joue ? -");
	str = ft_strfdup(&str, "Choisissez une rangée 'R2',", 1);
	str = ft_strfjoin1(&str, " ainsi que des allumettes 'N3'", 1);
	ft_print_notice_str(decal, width, ' ', str);
	str = ft_strfdup(&str, " --> R3 N2 (vous prenez ", 1);
	str = ft_strfjoin1(&str, "deux allumettes de la rangée trois) ", 1);
	ft_print_notice_str(decal, width, ' ', str);
	ft_print_notice_entry(decal, width, error);
	ft_print_notice_separator(decal, width, NULL, -1);
	return (ft_free_return(0, &str));
}

static int		ft_print_notice_entry(int decal, int width, int error)
{
	char	*str;

	if ((str = NULL) == NULL && (error == 2 || error == 3))
	{
		ft_print_notice_str(decal, width, ' ', "");
		ft_print_notice_str(decal, width, ' ', "- Erreur de saisie ! -");
		str = ft_strfdup(&str, "Veuillez suivre l'exemple ci-dessus, ", 1);
		str = ft_strfjoin1(&str, "sur la façon de jouer.", 1);
		ft_print_notice_str(decal, width, ' ', str);
	}
	if (error == 3)
	{
		str = ft_strfdup(&str, "Le nombre d'allumettes ou la rangée entrée", 1);
		str = ft_strfjoin1(&str, " n'est pas correct ...", 1);
		ft_print_notice_str(decal, width, ' ', str);
	}
	if (error == -2)
	{
		ft_print_notice_str(decal, width, ' ', "");
		ft_print_notice_str(decal, width, ' ', "- Erreur de génération ! -");
		str = ft_strfdup(&str, "Veuillez nous excuser pour le dérangement.", 1);
		ft_print_notice_str(decal, width, ' ', str);
	}
	ft_print_easter_eggs(decal, width, ' ', error);
	return (ft_free_return(0, &str));
}

static int		ft_print_notice_error(int decal, int width, char *bin)
{
	char	*str;

	str = NULL;
	ft_print_notice_separator(decal, width, NULL, -1);
	ft_print_notice_str(decal, width, ' ', "");
	ft_print_notice_str(decal, width, ' ', "- Règle du jeu ! -");
	str = ft_strfdup(&str, "Ne pas prendre la dernière allumette ...", 1);
	ft_print_notice_str(decal, width, ' ', str);
	ft_print_notice_str(decal, width, ' ', "");
	ft_print_notice_str(decal, width, ' ', "- Comment on y joue ? -");
	str = ft_strfdup(&str, "Choisissez un type de partie ", 1);
	str = ft_strfjoin1(&str, "'solo' ou 'versus'", 1);
	ft_print_notice_str(decal, width, ' ', str);
	str = ft_strfdup(&str, bin, 1);
	str = ft_strfjoin1(&str, " solo   (HUMAIN <-> MACHINE)", 1);
	ft_print_notice_str(decal, width, ' ', str);
	str = ft_strfdup(&str, bin, 1);
	str = ft_strfjoin1(&str, " versus (HUMAIN <-> HUMAIN) ", 1);
	ft_print_notice_str(decal, width, ' ', str);
	ft_print_notice_separator(decal, width, NULL, -1);
	ft_putchar('\n');
	return (ft_free_return(0, &str));
}

static void		ft_print_notice_separator(int d, int w, char *str, int choice)
{
	if (!choice && str != NULL)
	{
		ft_putchar_loop(' ', d);
		ft_putchar('_');
		if (*str == '-')
			ft_putstr("\033[1m");
	}
	else if (choice > 0 && str != NULL)
	{
		if (*str == '-')
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

static void		ft_print_notice_str(int decal, int width, int c, char *str)
{
	int		i;
	int		diff;
	int		length;

	ft_print_notice_separator(decal, width, str, 0);
	width -= decal + 2;
	length = ft_strlen(str);
	i = -1;
	while (*(str + (++i)))
	{
		if (!ft_isprint(*(str + i)) && ++i)
			--length;
	}
	diff = (width - length) / 2;
	ft_putchar_loop(c, diff);
	ft_putstr(str);
	diff = width - (diff + length);
	ft_putchar_loop(c, diff);
	ft_print_notice_separator(decal, width, str, 1);
	ft_putchar('\n');
	return ;
}
