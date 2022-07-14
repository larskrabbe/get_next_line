/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 06:21:17 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/07/14 12:25:16 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	lookfor(int fd, char *buffer, char *tmp_buf)
{
	ssize_t	len;
	ssize_t	i;
	ssize_t	pos;

	pos = 0;
	tmp_buf[0] = 0;
	len = read(fd, buffer, BUFFERSIZE);
	if (len == 0 || len == -1)
		return (len);
	i = 0;
	while (i < len && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (i + pos < len)
	{
		tmp_buf[pos] = buffer[i + pos];
		pos++;
	}
		tmp_buf[pos] = '\0';
	return (i);
}
