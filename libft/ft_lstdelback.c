/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrmback.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 16:21:44 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/21 16:21:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstdelback(t_list *head)
{
	t_list		*curr;
	t_list		*back;

	curr = head;
	back = NULL;
	if (!curr)
		return (NULL);
	while (curr->next)
	{
		back = curr;
		curr = curr->next;
	}
	if (back)
		back->next = NULL;
	if (curr == head)
		head = NULL;
	free(curr);
	return (head);
}
