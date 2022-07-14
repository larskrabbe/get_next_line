/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:27:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/14 15:04:16 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*rec_str_join(int fd, char *ptr, ssize_t size, char *tmp_buf)
{
	char		buffer[BUFFERSIZE];
	ssize_t		i;

	i = lookfor(fd, buffer, tmp_buf);
	if (i == BUFFERSIZE && buffer[i - 1] != '\n')
	{	
		ptr = rec_str_join(fd, ptr, size + i, tmp_buf);
		if (ptr == NULL)
			return (NULL);
	}
	else if ((i == 0 && size == 0) || (int) i == -1)
		return (NULL);
	else
	{
		ptr = malloc (sizeof(char) * (size + 1 + i));
		if (ptr == NULL)
			return (NULL);
		ptr[size + i] = '\0';
	}
	while (i-- > 0)
		ptr[size + i] = buffer[i];
	return (ptr);
}

char	*get_next_line(int fd)
{
	t_variabeln		v;
	static char		sta_buf[1024][BUFFERSIZE + 4];

	v.ptr = NULL;
	v.k = 0;
	v.i = 0;
	if (fd > 1024 || fd < 0 || BUFFERSIZE < 1)
		return (NULL);
	while (sta_buf[fd][v.i] != '\0' && sta_buf[fd][v.i] != '\n')
		v.i++;
	v.tmp = v.tmp_buf;
	if (sta_buf[fd][v.i] == '\n')
		v.tmp = sta_buf[fd] + v. i + 1;
	if (sta_buf[fd][v.i] == '\n')
		v.ptr = malloc(sizeof(char) * (v.i++ + 1));
	else
		v.ptr = rec_str_join(fd, v.ptr, v.i, v.tmp_buf);
	while ((v.k < BUFFERSIZE /*|| *(v.tmp + v.k) != '\0'*/) && v.ptr != NULL)
	{
		if (v.i > v.k)
			v.ptr[v.k] = sta_buf[fd][v.k];
		sta_buf[fd][v.k] = *(v.tmp + v.k);
		v.k++;
	}
	
	return (v.ptr);
}
