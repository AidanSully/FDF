/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:24:43 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/10 14:24:45 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(const char *s)
{
	unsigned long	length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}
