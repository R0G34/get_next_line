#include "get_next_line.h"

int	len_limit(char *str, int limit)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != limit)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	len = len_limit(str, '\0');
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0' || *str == (unsigned char)c)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	len = len_limit(s1, '\0') + len_limit(s2, '\0');
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (free(result), NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (free(s1), result);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	lenS;
	size_t	i;
	char	*result;

	i = 0;
	lenS = len_limit(s, '\0');
	if (start > lenS)
		return (free(s), NULL);
	if (len > lenS - start)
		len = lenS - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !result)
		return (free(s), NULL);
	while (start < lenS && i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}