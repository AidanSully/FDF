/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printmatrix.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/27 17:14:29 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/05 15:46:25 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i] != '\0')
		{
			ft_putchar(arr[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}