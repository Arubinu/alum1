/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:30:43 by apergens          #+#    #+#             */
/*   Updated: 2013/11/23 15:15:26 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + (++i - 1)))
	{
		if (*(s + (i - 1)) == c)
			return (i - 1);
	}
	if (*(s + (i - 1)) == c)
			return (i - 1);
	return (-1);
}
