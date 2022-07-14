/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:28 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/14 12:27:12 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<unistd.h>
# include	<stdlib.h>

# ifndef BUFFERSIZE
#  define BUFFERSIZE 42
# endif

typedef struct s_variabeln
{
	ssize_t		i;
	char		*ptr;
	ssize_t		k;
	char		*tmp;
	char		tmp_buf[BUFFERSIZE];
}t_variabeln;

int		lookfor(int fd, char *buffer, char *tmp_buf);
char	*get_next_line(int fd);

#endif