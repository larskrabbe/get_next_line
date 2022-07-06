/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:25 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/06 10:07:07 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"
#include    <stdio.h> //del later

int	reactiv_realloc(char *dst,char *remainder, char *buffer)
{
	int		i;
	char	*tmp;
	int		len;//will be a struct
	int		k;

	i = 0;
	len = 0;
	k = 0;
	while (buffer[i] != '\0' || buffer[i] != '\n')// maybe i need to  see if i == BUFFERSIZE
		i++;
	while (dst[len] != '\0' || dst[len] != '\n' || dst == NULL)
		len++;
	tmp = malloc(size_of(char) * (len + i));
	if (tmp == NULL)
		return (1);
	tmp[len + i + 1 ] = '\0'
	while (i >= 0)
		tmp[len + i] = buffer[i--];// doesnt work like that
	while (i + k <= BUFFERSIZE)
		remainder[k] = buffer[i + k++];
	while (len >= 0)
		tmp[len] = dst[len--];
	if (dst == NULL)
	free(dst);
	dst = tmp;
	if (k > 0)
		return(1);
	return (0);
}

char    *get_next_line(int fd)
{
	char			buffer[BUFFERSIZE];
	char			*str;
	static char 	remainder[BUFFERSIZE];

	if(reactiv_realloc(str,remainder,remainder))
		return (str);
	while(read(fd,(buffer),BUFFERSIZE))
	{
		if(reactiv_realloc(str,remainder,buffer))
			return (str);
	}
	return (NULL);
}