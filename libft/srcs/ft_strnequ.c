/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/11/26 13:51:46 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*(s1 + (++i)) && *(s1 + i) == *(s2 + i) && i < (int)n)
		;
	if ((*(s1 + i) || *(s2 + i)) && *(s1 + i) != *(s2 + i) && i < (int)n)
		return (0);
	return (1);
}
