/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:32 by gmunoz            #+#    #+#             */
/*   Updated: 2023/10/23 17:22:05 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (NULL);
		if (byte_nb == 0)
			break ;
		buffer[byte_nb] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*leftovers(char *temp)
{
	int		i;
	char	*backup;

	i = 0;
	while (temp[i] != 0 && temp[i] != '\n')
		i++;
	if (temp[i] == 0 || temp[1] == 0)
		return (0);
	backup = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	return (backup);
}

static char	*extract(char *newstr)
{
	int		i;
	char	*final_str;

	i = 0;
	while (newstr[i] != 0 && newstr[i] != '\n')
		i++;
	final_str = ft_substr(newstr, 0, i + 1);
	if (*final_str == '\0')
	{
		free(final_str);
		final_str = NULL;
	}
	return (final_str);
}

char	*get_next_line(int fd)
{
	char		*newstr;
	char		*temp;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	newstr = txt_split(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!newstr)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	temp = newstr;
	backup = leftovers(temp);
	if (backup != 0)
	{
		newstr = extract(newstr);
		free(temp);
		temp = NULL;
	}
	return (newstr);
}
