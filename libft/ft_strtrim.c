/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 17:19:32 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/14 17:19:33 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int				ft_begin(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static unsigned long	ft_strtrimlen(char const *s)
{
	unsigned long	front;
	unsigned long	back;
	unsigned long	length;
	int				i;

	front = 0;
	back = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		front++;
		i++;
	}
	length = ft_strlen(s) - 1;
	while (s[length] == ' ' || s[length] == '\n' || s[length] == '\t')
	{
		back++;
		length--;
	}
	if (front + back > ft_strlen(s))
		return (0);
	return (ft_strlen(s) - front - back);
}

char					*ft_strtrim(char const *s)
{
	char			*str;
	int				i;
	unsigned long	j;

	str = NULL;
	i = ft_begin(s);
	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ft_strtrimlen(s) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < ft_strtrimlen(s))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
