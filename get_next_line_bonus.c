/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:11:33 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/01 14:31:00 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (i <= BUFFER_SIZE && fd < FOPEN_MAX && fd >= 0)
			buffer[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		line = ft_create(line, buffer[fd]);
		cleanbuffer(buffer[fd], &flag);
	}
	return (line);
}
