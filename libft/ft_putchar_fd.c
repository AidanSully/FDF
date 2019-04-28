/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:52:37 by asulliva      #+#    #+#                 */
/*   Updated: 2019/01/14 13:52:38 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
