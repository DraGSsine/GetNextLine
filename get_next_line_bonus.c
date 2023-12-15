/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:39:23 by youchen           #+#    #+#             */
/*   Updated: 2023/12/15 15:57:45 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, ++i, ft_strlen(str)));
}

char	*get_the_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (ft_substr(str, 0, ++i));
}

static char	*read_and_process_buffer(int fd, char *left)
{
	char	buffer[BUFFER_SIZE + 1];
	int		r;

	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		buffer[r] = '\0';
		left = ft_strjoin(left, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	if (r == -1)
	{
		free(left);
		left = NULL;
		return (NULL);
	}
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*line;
	char		*ret;

	line = NULL;
	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left[fd] = read_and_process_buffer(fd, left[fd]);
	if (!left[fd])
		return (NULL);
	if (ft_strchr(left[fd], '\n'))
	{
		line = get_the_line(left[fd]);
		ret = get_left_string(left[fd]);
		return (free(left[fd]), left[fd] = NULL, left[fd] = ret, line);
	}
	if (*left[fd])
	{
		line = ft_strjoin(line, left[fd]);
		return (free(left[fd]), left[fd] = NULL, line);
	}
	return (free(left[fd]), left[fd] = NULL, NULL);
}
