/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:04:09 by nireher-          #+#    #+#             */
/*   Updated: 2023/12/11 03:19:01 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_pass(int fd)
{
	char			*buf;
	int				nbytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbytes = 1; //nbytes should be initialized as 1 since 0 means EOF and does not enter the loop (i think¿?)
	nbytes = read(fd, buf, BUFFER_SIZE + 1);
	if (nbytes == -1) // error
	{
		free(buf);
		return (NULL);
	}
	buf[nbytes - 1] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*saved;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return NULL;
	saved = ft_read_and_pass(fd); // Does saved[fd] include \n?
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
