/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 08:27:07 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_return_mode(char *mode)
{
	static int	save;

	if (save)
		return (save - 1);
	save = 1;
	if (!ft_strcmp(mode, "solo"))
		save = 2;
	else if (!ft_strcmp(mode, "versus"))
		save = 3;
	return (save - 1);
}
