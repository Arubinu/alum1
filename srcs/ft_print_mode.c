/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 08:27:07 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ft_print_mode(int decal, int width, char *str, int mode)
{
	if (str == NULL)
		return ;
	if (--mode)
	{
		ft_putchar_loop(' ', decal + 1);
		ft_putstr("Joueur ");
		ft_putchar(ft_calc_alum(NULL, 1) + '1');
		ft_putchar_loop(' ', (width - (decal + 9)) - (ft_strlen(str) + 7) - 1);
	}
	else
		ft_putchar_loop(' ', width - (ft_strlen(str) + 7) - 1);
	ft_putstr("Mode : ");
	ft_putendl(str);
	return ;
}
