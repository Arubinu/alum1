/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 15:58:09 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character string to the console
*/

void	ft_putstr_fd(const char *s, int fd)
{
	char	*s2;

	s2 = (char *)s;
	while (*s2 != '\0')
		ft_putchar_fd(*s2++, fd);
	return ;
}
