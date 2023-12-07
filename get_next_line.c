/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:04:09 by nireher-          #+#    #+#             */
/*   Updated: 2023/12/07 23:29:43 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_pass(int fd, char *line)
{
	char			*buf;
	int				nbytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbytes = read(fd, buf, BUFFER_SIZE + 1);
	if (nbytes == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[nbytes] = '\0';
	line = ft_strjoin(line, buf);
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\n'))
		return (line);
	else
	{
		while (!(ft_strchr(line, '\n')))
		{
			line = ft_read_and_pass(fd, line);
		}
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char 		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return NULL;
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	saved = ft_read_and_pass(fd, line);
	return (saved);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/nireher-/get_next_line/miau.txt", O_RDONLY);
	printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}
