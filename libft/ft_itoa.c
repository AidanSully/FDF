/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:22:48 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/17 11:23:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long int		ft_isnegative(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static int			ft_len(long int nbr)
{
	int		len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char			*ft_iszero(void)
{
	char		*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char				*ft_itoa(int nbr)
{
	int			len;
	int			flag;
	char		*str;

	flag = 0;
	if (nbr < 0)
		flag = 1;
	if (nbr == 0)
		return (ft_iszero());
	len = ft_len(nbr);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = ft_isnegative(nbr % 10) + '0';
		nbr = ft_isnegative(nbr / 10);
		len--;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}
