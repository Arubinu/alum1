/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 11:25:45 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	ret = NULL;
	while (lst)
	{
		temp = f(lst);
		temp = ft_lstnew(temp->content, temp->content_size);
		if (new == NULL)
		{
			new = temp;
			ret = temp;
		}
		else
		{
			new->next = temp;
			new = new->next;
		}
		lst = lst->next;
	}
	return (ret);
}
