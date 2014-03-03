/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/19 09:16:55 by apergens          #+#    #+#             */
/*   Updated: 2013/11/20 10:23:24 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char)* (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, (char *)s1);
	return (s2);
}
