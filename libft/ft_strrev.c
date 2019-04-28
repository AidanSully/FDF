/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:33:37 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/20 12:33:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrev(char *str)
{
	unsigned long		i;
	unsigned long		j;
	char				*s;

	i = 0;
	j = ft_strlen(str) - 1;
	s = (char*)malloc(sizeof(char) * j + 1);
	if (!s)
		return (NULL);
	while (i < ft_strlen(str))
	{
		s[i] = str[j];
		i++;
		j--;
	}
	s[i] = '\0';
	return (s);
}
