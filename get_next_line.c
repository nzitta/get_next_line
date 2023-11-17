/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher- <nireher-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:04:09 by nireher-          #+#    #+#             */
/*   Updated: 2023/11/17 20:24:09 by nireher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf[100];
	ssize_t		nbytes;

	if (fd == -1 || nbytes == 0)
		return NULL;
	else
	{
		nbytes = read(fd, buf, sizeof(buf));
	}
	buf[nbytes] = '\0';
	return (buf);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/nireher-/get_next_line/miau.txt", O_RDONLY);
	printf("line is %s\nand file descriptor is %d", get_next_line(fd), fd);
	return (0);
}
