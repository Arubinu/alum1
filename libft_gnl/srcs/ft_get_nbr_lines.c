/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by apergens          #+#    #+#             */
/*   Updated: 2014/02/13 14:10:17 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int		ft_get_nbr_lines(const char *file)
{
	int			fd;
	int			rd;
	int			ret;
	char		*buffer;

	ret = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buffer == NULL && file != NULL && *file != '\0')
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd <= -1)
		return (-1);
	while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		*(buffer + rd) = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
			ret++;
	}
	free(buffer);
	close(fd);
	if (rd == EOF)
		return (-1);
	return (ret);
}
