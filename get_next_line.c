/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:04:09 by nireher-          #+#    #+#             */
/*   Updated: 2024/02/24 00:49:11 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buf)
{
	int	nbytes;

	nbytes = read(fd, buf, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(buf);
		return NULL;
	}
	buf[nbytes] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	char	*buf;
	static char	*saved_text;

	if (BUFFER_SIZE <= 0)
		return NULL;
	buf = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return NULL;
	saved_text = read_file(fd, buf);
	return (saved_text);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/nireher-/gnl/miau.txt", O_RDONLY);
	if (fd != -1)
	{
		printf("%s", get_next_line(fd));
		close (fd);
	}
	else
		printf("error\n: %d is fd number", fd);
	
	return (0);
}