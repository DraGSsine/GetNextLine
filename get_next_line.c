#include "get_next_line.h"

char *get_left_string(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (ft_substr(str, ++i, ft_strlen(str)));
}
char *get_the_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (ft_strjoin(ft_substr(str, 0, i), "\n"));
}

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static char *left;
	int readed_chars;
	char *line = NULL;
	char *ret = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	if (left)
	{
		if (ft_strchr(left, '\n'))
		{
			line = get_the_line(left);
			ret = get_left_string(left);
			free(left);
			left = ret;
			return line;
		}
		line = ft_strjoin(line, left);
		free(left);
		left = NULL;
	}

	while (1)
	{
		readed_chars = read(fd, buffer, BUFFER_SIZE);
		if (readed_chars <= 0)
			break;
		buffer[readed_chars] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			ret = get_the_line(line);
			left = get_left_string(line);
			free(line);
			return ret;
		}
	}

	if (readed_chars == 0 && line != NULL)
	{
		if (line[0] == '\0')
		{
			free(line);
			return NULL;
		}
		return line;
	}

	free(line);
	return NULL;
}

// int main()
// {
// 	// 1char.txt //multiple_nl.txt
// 	int fd = open("/Users/youchen/francinette/tests/get_next_line/fsoares/1char.txt", O_RDONLY);
// 	// int fd = open("file.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
