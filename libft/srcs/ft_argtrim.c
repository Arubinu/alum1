/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 23:14:21 by apergens          #+#    #+#             */
/*   Updated: 2013/12/25 23:17:10 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_argtrim(char **str)
{
	int		len;

	ft_putendl(*str);
	if (str == NULL || *str == NULL || **str == '\0')
		return ;
	len = ft_strlen(*str) - 1;
	if (**str == '"' && *(*str + len) == '"')
	{
		*(*str + len) = '\0';
		*str += 1;
	}
	return ;
}
