#include "get_next_line.h"

static char	*txt_split(int fd, char *buffer, char *backup)
{
	ssize_t	byte_nb;
	char	*temp;

	byte_nb = 1;
	while (byte_nb != 0)
	{
		byte_nb = read(fd, buffer, BUFFER_SIZE);
		if (byte_nb == -1)
			return (free(backup), NULL);
		if (byte_nb == 0)
			break ;
		buffer[byte_nb] = '\0';
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		if (!backup)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static int	if_leftovers(char *newstr)
{
	int		i;

	i = 0;
	while (newstr[i] != '\0' && newstr[i] != '\n')
		i++;
	if (newstr[i] == '\n')
		i++;
	if (newstr[i] == '\0')
		return (0);
	return (i);
}

static char	*leftovers(char *newstr)
{
	char	*backup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!newstr)
		return (NULL);
	while (newstr[i] != '\n')
		i++;
	backup = ft_calloc(ft_strlen(newstr) - i, 1);
	if (!backup)
		return (free(newstr), NULL);
	i++;
	while (newstr[i + j] != '\0')
	{
		backup[j] = newstr[i + j];
		j++;
	}
	return (free(newstr), backup);
}

static char	*extract(char *newstr)
{
	int		i;
	int		j;
	char	*final_str;

	i = 0;
	j = 0;
	if (!newstr)
		return (NULL);
	while (newstr[i] != '\0' && newstr[i] != '\n')
		i++;
	if (newstr[i] == '\n')
		i++;
	final_str = ft_calloc(i + 1, 1);
	if (!final_str)
		return (free(newstr), NULL);
	while (j < i)
	{
		final_str[j] = newstr[j];
		j++;
	}
	return (final_str);
}

char	*get_next_line(int fd)
{
	char		*newstr;
	char		*final_str;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free(backup), backup = NULL, NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(backup), backup = NULL, NULL);
	newstr = txt_split(fd, buffer, backup);
	backup = NULL;
	free(buffer);
	if (!newstr)
		return (NULL);
	final_str = extract(newstr);
	if (!final_str)
		return (NULL);
	if (if_leftovers(newstr) == 0)
		return (free(newstr), final_str);
	backup = leftovers(newstr);
	if (!backup)
		return (free(final_str), NULL);
	return (final_str);
}
