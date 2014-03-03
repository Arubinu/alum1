/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 16:00:27 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
