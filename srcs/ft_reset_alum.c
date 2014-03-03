/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_alum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:32:44 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_reset_alum(char **nbr, int choice, int error)
{
	char		*itoa;
	static int	save;

	if (error == 1)
		return (1);
	itoa = NULL;
	if (choice)
	{
		save = 4;
		if (*nbr != NULL && ((*(*nbr + 3) && *(*nbr + 3) != ' ')
			|| (*(*nbr + 3) == ' ' && ((save = ft_atoi(*nbr + 4)) < 4
			|| ft_strcmp((itoa = ft_itoa(save)), *nbr + 4)))))
		{
			ft_strdel(nbr);
			ft_strdel(&itoa);
			save = (save < 4) ? 4 : save;
			if (error == -1)
				return (ft_free_return(1, nbr));
			return (ft_free_return(2, nbr));
		}
		ft_all_alum(0, save, -1, 0);
		return (ft_free_return(0, nbr));
	}
	save = (save < 4) ? 4 : save;
	return (ft_free_return(save, &itoa));
}
