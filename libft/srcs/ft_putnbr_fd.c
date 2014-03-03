/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2014/02/13 15:25:22 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writing a number in the console
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*tmp;

	if ((tmp = ft_itoa(n)))
	{
		ft_putstr_fd(tmp, fd);
		free(&tmp);
	}
	else
		ft_putchar_fd('0', fd);
	return ;
}
