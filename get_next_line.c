	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:23:09 by ayblin            #+#    #+#             */
/*   Updated: 2021/12/09 03:40:59 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_str = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!s_str)
		s_str = ft_strdup("");
	if (read_file(fd, &s_str, &buffer, &line) && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}

int	read_file(int fd, char **s_str, char **buffer, char **line)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (!ft_strchr(*s_str, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		tmp = *s_str;
		*s_str = ft_strjoin(*s_str, *buffer);
		free_ptr(tmp);
	}
	free_ptr(*buffer);
	get_line(line, s_buff);
	return (bytes_read);
}

char	*get_line(char	**line, char **s_str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *s_str;
	while ((*s_str)[i] != '\n' && (*s_str)[i] != '\n')
		i++;
	if (ft_strchr(*s_str, '\n'))
	{
		*line = ft_substr(s_str, 0, i + 1);
		
	}
	else
	
}
