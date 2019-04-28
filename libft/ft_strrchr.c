/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:19:46 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 14:19:48 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	if (i == 0)
		return ((char*)&s[i]);
	return (NULL);
}
