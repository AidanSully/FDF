/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:26:02 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/11 15:26:04 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	if (s1 && s2)
	{
		while (str1[i] == str2[i] && str1[i] != '\0' && i < len - 1)
			i++;
	}
	return (str1[i] - str2[i]);
}
