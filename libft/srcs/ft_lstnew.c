/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 11:25:45 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret != NULL)
	{
		if (content != NULL)
		{
			ret->content = ft_memalloc(content_size);
			ft_memcpy(ret->content, content, content_size);
		}
		else
			ret->content = NULL;
		ret->content_size = (ret->content != NULL) ? content_size : 0;
		ret->next = NULL;
	}
	return (ret);
}
