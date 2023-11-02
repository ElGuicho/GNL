#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	char	*total;
	int		i;

	i = 0;
	if (!count || !size)
		return (NULL);
	total = malloc(count * size);
	if (!total)
		return (NULL);
	while (i < count * size)
	{
		total[i] = 0;
		i++;
	}
	return (total);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str || !c)
		return (NULL);
	if ((unsigned char)c == '\0')
	{
		ptr = (char *)&str[ft_strlen(str)];
		return (ptr);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	newstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!newstr)
		return (free(s1), NULL);
	while (s1 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	return (free(s1), newstr);
}
