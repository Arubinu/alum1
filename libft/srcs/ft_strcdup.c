/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/19 09:16:55 by apergens          #+#    #+#             */
/*   Updated: 2014/02/19 21:23:22 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c)
{
	int		len;
	char	*s2;

	len = ft_strcchr(s1, c);
	len = (len == -1) ? (int)ft_strlen(s1) : len;
	s2 = (char *)malloc(sizeof(char)* (len + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strncpy(s2, (char *)s1, len);
	*(s2 + len) = '\0';
	return (s2);
}
