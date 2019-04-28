/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:06:50 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/10 18:06:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*dest;
	const char		*source;
	size_t			left;
	size_t			len;

	dest = dst;
	source = src;
	left = size;
	while (left-- != 0 && *dest != '\0')
		dest++;
	len = dest - dst;
	left = size - len;
	if (left == 0)
		return (len + ft_strlen(source));
	while (*source != '\0')
	{
		if (left != 1)
		{
			*dest++ = *source;
			left--;
		}
		source++;
	}
	*dest = '\0';
	return (len + (source - src));
}
