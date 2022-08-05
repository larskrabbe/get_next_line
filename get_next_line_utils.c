/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:17 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/17 18:08:18 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	lookfor(int fd, char *buffer, char *sta_buf)
{
	ssize_t	len;
	ssize_t	i;
	ssize_t	pos;

	pos = 0;
	sta_buf[0] = '\0';
	len = read(fd, buffer, BUFFER_SIZE);
	if (len == 0 || len == -1)
		return (len);
	i = 0;
	while (i < len && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		while (pos + i < len)
		{
			sta_buf[pos] = buffer[i + pos];
			pos++;
		}
		sta_buf[pos] = '\0';
	}
	return (i);
}
