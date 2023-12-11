/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:26:19 by youchen           #+#    #+#             */
/*   Updated: 2023/12/11 21:23:00 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s1)
{
	int i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i])
	{
		i++;
	}
	return (i);
}
char *ft_strdup(char *s1)
{
	size_t i;
	size_t len;
	char *string;

	string = NULL;
	i = 0;
	len = ft_strlen(s1);
	string = malloc(len + 1);
	if (!string)
	{
		return (NULL);
	}
	while (i <= len)
	{
		string[i] = s1[i];
		i++;
	}
	return (string);
}
char *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t s_len;
	char *ptr_str;
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	ptr_str = malloc(len + 1);
	if (ptr_str == NULL)
		return (NULL);
	while (i < len)
		ptr_str[i++] = s[start++];
	ptr_str[len] = '\0';
	return (ptr_str);
}
char *ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
char *ft_strjoin(char *s1, char *buff)
{
	size_t i;
	size_t j;
	char *str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(buff) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s1) + ft_strlen(buff)] = '\0';
	free(s1);
	return (str);
}
