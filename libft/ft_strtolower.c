/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtolower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 13:01:21 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/20 13:01:22 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strtolower(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str[i] = '\0';
	return (str);
}
