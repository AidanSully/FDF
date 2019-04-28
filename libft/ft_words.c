/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_words.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:41:09 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/05 15:57:02 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_words(const char *s, char c)
{
	int		words;
	int		flag;

	flag = 0;
	words = 0;
	if (!s || !c)
		return (0);
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			words++;
		}
		s++;
	}
	return (words);
}