/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:30:25 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/20 12:30:27 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstcount(t_list *head)
{
	t_list		*counter;
	int			len;

	counter = head;
	len = 0;
	while (counter != NULL)
	{
		len++;
		counter = counter->next;
	}
	return (len);
}
