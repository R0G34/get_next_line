#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*readd;
	int		str;

	readd = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readd)
		return (free(buffer), NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		str = read(fd, readd, BUFFER_SIZE);
		if (str == -1)
			return (free(readd), free(buffer), NULL);
		readd[str] = '\0';
		if (readd[0] == '\0')
			return (free(readd), buffer);
		buffer = ft_strjoin(buffer, readd);
		if (!buffer)
			return (free(readd), free(buffer), NULL);
	}
	free(readd);
	return (buffer);
}

static char	*delete(char *buffer)
{
	char	*result;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	result = (char *)malloc((len_limit(buffer, '\0') - i + 1) \
	* sizeof(char));
	if (!result)
		return (free(buffer), NULL);
	while (buffer[i] != '\0')
	{
		result[j] = buffer[i];
		i++;
		j++;
	}
	result[j] = '\0';
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL || !ft_strchr(buffer, '\n'))
	{
		buffer = ft_read(fd, buffer);
		if (!buffer)
			return (NULL);
	}
	if (ft_strchr(buffer, '\n'))
		line = ft_substr(buffer, 0, len_limit(buffer, '\n') + 1);
	else
		line = ft_substr(buffer, 0, len_limit(buffer, '\0') + 1);
	if (!line)
		return (NULL);
	buffer = delete(buffer);
	if (buffer[0] == '\0')
		free(buffer);
	return (line);
}

int	main()
{
	char	*lines;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	lines = "";
	i = 1;
	while (lines)
	{
		lines = get_next_line(fd);
		if (lines != NULL)
			printf("Line %d:\n%s\n", i, lines);
			i++;
		free(lines);
	}
	printf("\n");
	system("leaks -q a.exe");
	return (0);
}