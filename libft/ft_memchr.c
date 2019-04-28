/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 19:20:31 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 19:20:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*s1;
	size_t				i;

	s1 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*s1 == (unsigned char)c)
			return (char*)s1;
		s1++;
		i++;
	}
	return (NULL);
}
