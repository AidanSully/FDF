/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 17:43:48 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/13 17:43:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strclr(char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
	return ;
}
