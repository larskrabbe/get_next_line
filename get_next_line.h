/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:28 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/17 17:34:00 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_variabeln
{
	ssize_t		i;
	char		*ptr;
	ssize_t		k;
	char		*tmp;
	char		tmp_buf[BUFFER_SIZE];
}t_variabeln;

int		lookfor(int fd, char *buffer, char *tmp_buf);
char	*get_next_line(int fd);

#endif