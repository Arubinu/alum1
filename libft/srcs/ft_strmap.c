/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/11/26 13:48:12 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(char)* (ft_strlen(s) + 1));
	while (*(s + (++i)))
		*(s2 + i) = (char)f(*(s + i));
	return (s2);
}
