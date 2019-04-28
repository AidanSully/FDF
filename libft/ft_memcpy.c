/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:22:13 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 17:22:14 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*destination;
	const char		*source;
	int				i;

	destination = dst;
	source = src;
	i = 0;
	if (n == 0)
		return (dst);
	while (n)
	{
		n--;
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
