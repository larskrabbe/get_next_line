/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:27:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/07 19:37:55 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h> //del later

#define BREAK '\n' // maybe keep it

int	lookfor(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != BREAK && buffer[i] != '\0' && i < BUFFERSIZE)
		i++;
	return (i);
}


int	my_str_len(char *str)
{
	int i;
	if (str == NULL)
		return(0);
	i = 0;
	while (str[i] != '\0' )
		i++;
	return (i);
}

char *copy(char *ptr, char *buffer, char *sta_buf, int n, int len_buf)
{
	int	i;
	int k;
	char *dst;
	int j;

	i = 0;
	k = 0;
	j = 0;
	dst = malloc(4 * (n + my_str_len(ptr)));
	if (dst == NULL)
		return (NULL);
	while (j < my_str_len(ptr) && ptr != NULL)
	{
		dst[j] = ptr[j];
		j++;
	}
	while (n + my_str_len(ptr) >= i + j)
	{
		dst[j+ i]= buffer[i];
		i++;
	}
	dst[j + i + k] = '\0';
	while (i + k < len_buf)
	{
		sta_buf[k] = buffer[k + i];
		k++;
	}
	sta_buf[k] = '\0';
	free(ptr);
	return (dst);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFERSIZE];
	char		*ptr;
	int			i;
	static char	sta_buf[BUFFERSIZE] = "";
	int 		len_buf;
	
	ptr = NULL;
		if (sta_buf[0] != '\0')
		{
			len_buf = my_str_len(sta_buf);
			i = lookfor(sta_buf);
			ptr = copy(ptr, sta_buf, sta_buf, i, len_buf);
			if (i < len_buf)
				return (ptr);
		}
		while (1)
		{
			len_buf = read(fd, buffer, BUFFERSIZE);
			if ( len_buf <= 0)
				return (ptr);
			i = lookfor(buffer);
			ptr = copy(&(*ptr), buffer, sta_buf, i, len_buf);
			if (i < BUFFERSIZE || ptr == NULL)
				return (ptr);
		}
}
