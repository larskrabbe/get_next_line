/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe < lkrabbe@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:25 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/05 16:16:55 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"
#include    <stdio.h> //del later

char	*quickcopy(char *buffer,size_t n)
{
	char	*str;
	size_t	pos;

	pos = 0;
	str = malloc(sizeof(char)*(n+1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (n > pos)
		{
			str[pos] = buffer[pos];
			pos++;
		}
	}
	return (str);
}

char    *get_next_line(int fd)
{
	char			buffer[BUFFERSIZE + 1];
	size_t			i;
	static size_t	counter = 0;
	char			*str;
	int				tmp;
	i = 0;
	if(i <= counter)
	{
		tmp = read(fd,(buffer),BUFFERSIZE);
		i += tmp;
		printf("\ntmp == %i || i == %zu || counter == %i",tmp,i,counter);
		if (tmp <= 0)
			return (quickcopy("Error",6));
	}
	counter = i;;
	str = quickcopy(buffer,tmp);
	return (str);
}