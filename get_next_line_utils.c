/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:59:31 by nireher-          #+#    #+#             */
/*   Updated: 2024/02/23 23:57:12 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t num_size)
{
	const size_t total_len = num * num_size;
	void *buffer;

	if (!num || !num_size)
		return (malloc(0));
	buffer = (void *)malloc(total_len);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, total_len);
	return (buffer);
}