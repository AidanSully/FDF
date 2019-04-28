/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 16:01:17 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/18 16:01:19 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	head = new;
	while (lst->next)
	{
		new->next = f(lst->next);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
