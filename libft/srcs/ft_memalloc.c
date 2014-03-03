/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/11/23 20:27:04 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = (char *)malloc(size);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}
