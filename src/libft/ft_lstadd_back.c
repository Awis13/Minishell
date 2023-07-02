/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:08:57 by nipostni          #+#    #+#             */
/*   Updated: 2022/02/22 12:06:47 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst != NULL && *lst != NULL)
	{
		elem = *lst;
		elem = ft_lstlast(*lst);
		elem->next = new;
		return ;
	}
	*lst = new;
}
