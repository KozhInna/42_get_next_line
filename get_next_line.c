/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:58:14 by ikozhina          #+#    #+#             */
/*   Updated: 2024/12/20 11:43:51 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*handle_buffer(char **buffer, char *line);
static int	read_to_buffer(int fd, char **buffer, char **line);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer && *buffer)
		{
			line = handle_buffer(&buffer, line);
			if (!line || ft_strchr(line, '\n'))
				return (line);
		}
		status = read_to_buffer(fd, &buffer, &line);
		if (status == 1)
			return (line);
		if (status == 0)
			return (NULL);
	}
}

static char	*handle_buffer(char **buffer, char *line)
{
	char	*ptr_newline;
	char	*temp;

	temp = line;
	line = ft_strjoin_up_nl(line, *buffer);
	free(temp);
	if (!line)
		return (NULL);
	ptr_newline = ft_strchr(*buffer, '\n');
	if (ptr_newline)
		ft_memmove(*buffer, ptr_newline + 1, ft_strlen(ptr_newline));
	else
		(*buffer)[0] = '\0';
	return (line);
}

static int	read_to_buffer(int fd, char **buffer, char **line)
{
	ssize_t	bytes_read;

	if (!*buffer)
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		if (!*buffer)
			return (0);
		(*buffer)[0] = '\0';
	}
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*buffer);
		*buffer = NULL;
		if (bytes_read == 0 && *line && **line)
			return (1);
		free(*line);
		*line = NULL;
		return (0);
	}
	(*buffer)[bytes_read] = '\0';
	return (2);
}
