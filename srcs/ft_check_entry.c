/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/03/03 09:34:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_send_entry(int r, int n, char *entry);

int			ft_check_entry(char *entry)
{
	int		r;
	int		n;
	char	*tmp;
	char	*itoa;
	char	*space;

	if (entry != NULL && !ft_strcmp(entry, "42"))
		return (4);
	if (entry == NULL || *entry != 'R' || !ft_isdigit(*(entry + 1)))
		return (2);
	if ((space = ft_strchr(entry, ' ')) != NULL && *(space + 1) == 'N')
	{
		tmp = ft_strcdup((entry + 1), ' ');
		if ((r = ft_atoi(tmp)) && (itoa = ft_itoa(r)) && ft_strcmp(itoa, tmp))
			return (ft_free_return(2, &tmp));
		ft_strdel(&itoa);
		n = ft_atoi((space + 2));
		if ((itoa = ft_itoa(n)) && ft_strcmp(itoa, (space + 2)))
			return (ft_free_return(2, &tmp));
		ft_strdel(&itoa);
		return (ft_free_return(ft_send_entry(r, n, entry), &tmp));
	}
	else
		return (2);
	return (0);
}

static int	ft_send_entry(int r, int n, char *entry)
{
	int		all;

	if (n <= 0 || (all = ft_all_alum(-1, r, 0, 1)) == -1 || all < n)
		return (3);
	ft_all_alum(0, r, n, 0);
	ft_calc_alum(entry, 0);
	return (0);
}
