/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strftrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/12/24 16:37:38 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strftrim(char **s, int pfree)
{
	char	*ret;

	ret = ft_strtrim(*s);
	if (pfree == 1)
	{
		free(*s);
		*s = NULL;
	}
	return (ret);
}
