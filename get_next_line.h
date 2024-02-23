/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:00:53 by nireher-          #+#    #+#             */
/*   Updated: 2024/02/23 23:31:03 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

// BF as how much is the function going to read
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10

#endif

#include <stdio.h>
// open()
#include <fcntl.h>
// read()
#include <unistd.h>

char	*get_next_line(int fd);

#endif
