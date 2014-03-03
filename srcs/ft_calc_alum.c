/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_alum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:34:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_calc_alum_ia(void);

int				ft_calc_alum(char *entry, int get)
{
	static int	turn;

	if (!get)
	{
		if (turn == 1)
		{
			(void)entry;
			if (ft_return_mode(NULL) == 2)
				ft_calc_alum_ia();
		}
		turn = (turn + 1) % 2;
	}
	else if (get < 0)
		turn = 0;
	return (turn);
}

static void		ft_calc_alum_ia(void)
{
	return ;
}
