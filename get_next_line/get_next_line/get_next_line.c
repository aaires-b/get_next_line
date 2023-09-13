/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:03:56 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/13 19:33:28 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int 		flag;
	
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		cleanbuffer(buffer, &flag);
		return (NULL);
	}
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_create(line, buffer);
		cleanbuffer(buffer, &flag);
	}
	if ((read(fd, buffer, 0) < 0))
	{
		cleanbuffer(buffer, &flag);
		return (NULL);
	}
	return (line);
}

/*int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	
	char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}*/
