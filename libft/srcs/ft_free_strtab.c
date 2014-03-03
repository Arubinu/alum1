/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/02/16 05:07:22 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strtab(char ***str)
{
	int		i;

	i = -1;
	if (str == NULL || *str == NULL || **str == NULL)
		return ;
	while (*(*str + (++i)) != NULL)
		free (*(*str + i));
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return ;
}
