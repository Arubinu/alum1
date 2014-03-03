/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 07:22:14 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 07:29:54 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ft_print_prompt(char **entry, int error)
{
	if (entry != NULL && *entry != NULL && (!error || error == -1))
	{
		ft_putstr(" Choix précédent : ");
		ft_putendl(*entry);
	}
	ft_strdel(entry);
	ft_putstr(" Entrez votre choix : ");
	return ;
}
