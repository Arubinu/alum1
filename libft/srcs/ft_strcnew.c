/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 23:14:21 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 04:20:46 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcnew(char c, size_t n)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	ft_memset((void *)str, c, n);
	*(str + n) = '\0';
	return (str);
}
