/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:50:35 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 16:50:36 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*str;
	size_t				i;

	str = b;
	i = 0;
	if (len == 0)
		return (b);
	str = (unsigned char*)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
