/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 02:05:01 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 11:25:17 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	while (++i <= n)
	{
		if (*(s2 + (i - 1)) == '\0')
			b = 1;
		if (b)
			*(s1 + (i - 1)) = '\0';
		else
			*(s1 + (i - 1)) = *(s2 + (i - 1));
	}
	return (s1);
}
