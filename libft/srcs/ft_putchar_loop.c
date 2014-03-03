/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2013/11/22 12:42:39 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console several times
*/

void	ft_putchar_loop(char c, int nbr)
{
	int		i;

	i = -1;
	while (++i < nbr)
		ft_putchar(c);
	return ;
}
