/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:58:53 by gregor.buch       #+#    #+#             */
/*   Updated: 2023/07/21 13:48:09 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *left_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!left_str)
// 	{
// 		left_str = (char *)malloc(1 * sizeof(char));
// 		left_str[0] = '\0';
// 	}
// 	if (!left_str || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (left_str)
// 		while (left_str[++i] != '\0')
// 			str[i] = left_str[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
// 	free(left_str);
// 	return (str);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	index;

	index = 0;
	if (count == 0 || size == 0)
		return (ptr = malloc(count * size));
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	while (index < (count * size))
	{
		((unsigned char *)ptr)[index] = '\0';
		index++;
	}
	return ((unsigned char *)ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	char	*last_buffer;

	if (!s1 && !s2)
		return (malloc(1 * sizeof(char)));
	total_length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	last_buffer = malloc((total_length + 1) * sizeof(char));
	if (!last_buffer)
		return (NULL);
	while (*s1)
	{
		*last_buffer++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*last_buffer++ = *s2;
		s2++;
	}
	*last_buffer = '\0';
	last_buffer -= total_length;
	return (last_buffer);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = 0;
		index++;
	}
}
