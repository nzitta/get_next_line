/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nireher <nireher-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:59:31 by nireher-          #+#    #+#             */
/*   Updated: 2023/12/07 22:47:31 by nireher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t total;
	size_t count;
	char *joined;

	total = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * total + 1);
	if (!joined)
		return (NULL);
	count = 0;
	while (*s1)
	{
		*joined++ = *s1++;
		count++;
	}
	while (*s2)
	{
		*joined++ = *s2++;
		count++;
	}
	*joined = '\0';
	return (joined - count);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = c;
	while (*s && *s != a)
		s++;
	if (*s == a)
		return ((char *)s);
	return (0);
}