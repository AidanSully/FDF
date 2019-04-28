/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 14:44:49 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/05 15:31:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 10
# define VALIDATE(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);
#endif
