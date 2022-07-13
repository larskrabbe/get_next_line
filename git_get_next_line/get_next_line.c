/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:27:23 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/12 14:56:22 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h> //del later

int	lookfor(int fd, char *buffer, char *tmp_buf)
{
	int	len;
	int	i;
	int pos;

	pos = 0;
	len = read(fd,buffer,BUFFERSIZE);
	i = 0;
	while (i < len && buffer[i] != '\n' &&  buffer[i] != '\0')
		i++;
	if ( buffer[i] == '\n' ||  buffer[i] == '\0')
		i++;
	while (i + pos < len)
	{
		tmp_buf[pos] = buffer[i + pos];
		pos++;
	}
	if (pos != 0)
		tmp_buf[pos] = '\0';
	return (i);
}

char *rec_str_join(int fd,char *ptr,size_t size,char *tmp_buf)
{
	char	buffer[BUFFERSIZE];
	int		i;

	i = lookfor(fd, buffer,tmp_buf);
	if (i == BUFFERSIZE)
	{	
		ptr = rec_str_join(fd, ptr, size + i, &(tmp_buf[0]));
		if (ptr == NULL)
			return(NULL);
	}
	else if (i <= 0 && size == 0)
		return (NULL);
	else
	{
		ptr = malloc (sizeof(char) * (size + 1 + i));
		if (ptr == NULL)
			return(NULL);
		ptr[size  + i - 1] = '\0';
	}
//	printf(">>%s<<",tmp_buf);
	while ( i-- >= 0)
		ptr[size + i] = buffer[i];
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*ptr = NULL;
	static char sta_buf[BUFFERSIZE];
	int			i;
	char		tmp_buf[BUFFERSIZE];
	int 		k;
	
	k = 0;
	i = 0;
	while(sta_buf[i] != '\0' && sta_buf[i] != '\n')
		i++;
	if (sta_buf[i] == '\n')
	{
		i++;
		ptr = malloc(sizeof(char) * (i + 1));
		if (ptr == NULL)
			return (NULL);
		
		while (i > k)
		{
			ptr[k] = sta_buf[k];
			k++;
		}
		ptr[k] = '\0';
		while (k >= 0)
		{
			sta_buf[k] = sta_buf[k+i];
			printf("<%i>",sta_buf[k]);
			k--;
		}
		return (ptr);
	}
	printf("-->%s|",sta_buf);
	fflush(stdout);
	ptr = rec_str_join(fd, ptr, i, &(tmp_buf[0]));
	while ( i--  > 0)
		ptr[i] = sta_buf[i];
	k = 0;
	while (k <= BUFFERSIZE)
	{
		sta_buf[k] = tmp_buf[k];
	//	printf("|%c|",sta_buf[k]);
		k++;
	}
//printf("%i == >>%s<<",k,sta_buf);
//	fflush(stdout);
	return(ptr);
}
