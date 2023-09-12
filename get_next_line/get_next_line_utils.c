/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:48:51 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/12 20:07:02 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	if(!s)
		return(0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n' )
		i++;
	return(i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		j++;
		i++;
		if (s2[j] == '\n')
			break ;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	cleanbuffer(char *buffer, int *flag)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		buffer[i] = 0;
		i++;
	}
	if (buffer[i] == '\n')
	{
		buffer[i] = 0;
		*flag = 1;
		i++;
	}
	j = 0;
	while (buffer[i])
	{
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		j++;
		i++;
	}
}

/*void	cleanbuffer(char *buffer, int *flag)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while (buffer[i])
	{
		if (*flag == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			*flag = 1;
		buffer[i] = 0;
		i++;
	}
}*/