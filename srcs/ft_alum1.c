/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alum1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 08:27:07 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		main(int argc, char **argv)
{
	int		error;
	int		mode;
	char	*buff;

	error = (argc <= 1 || !(mode = ft_return_mode(*(argv + 1)))) ? 1 : -1;
	buff = ft_strdup("new");
	buff = (argc == 3) ? ft_strfjoin1(&buff, " ", 1) : buff;
	buff = (argc == 3) ? ft_strfjoin1(&buff, *(argv + 2), 1) : buff;
	while (ft_strcmp(buff, "exit") && ft_print_title())
	{
		if (error != -1 && (ft_strncmp(buff, "new", 2)
			|| (*(buff + 3) == ' ' && ft_atoi((buff + 3)) < 4)))
			error = ft_check_entry(buff);
		else if (!*(buff + 3) || *(buff + 3) == ' ')
			error = ft_reset_alum(&buff, 1, error);
		ft_print_notice(TITLE_DECAL, TERM_WIDTH, error, *argv);
		if (error == 1 || error == -2)
			return (-1);
		ft_print_mode(TITLE_DECAL, TERM_WIDTH, *(argv + 1), mode);
		if (!(error = ft_end_alum(&buff, *argv, error)))
			break ;
		if (error != -3 && !(error = 0))
			ft_get_next_line(STDIN_FILENO, &buff);
	}
	return (0);
}
