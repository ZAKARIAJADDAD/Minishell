/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:34:05 by zjaddad           #+#    #+#             */
/*   Updated: 2023/05/15 05:21:23 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !(*lst))
	{
		*lst = new;
		return;
	}
	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
}