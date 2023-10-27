/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:32 by gmunoz            #+#    #+#             */
/*   Updated: 2023/10/27 17:47:04 by gmunoz           ###   ########.fr       */
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
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		if (!backup)
			return (temp = NULL, NULL);
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
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	if (temp[i] == 0)
	{
		backup = ft_calloc(2, 1);
		if (!backup)
			return (NULL);
		backup[0] = '&';
		return (backup);
	}
	backup = ft_substr(temp, i, ft_strlen(temp) - i);
	if (!backup)
		return (NULL);
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
	if (!final_str)
		return (NULL);
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

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free(backup), backup = NULL, NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(backup), backup = NULL, NULL);
	newstr = txt_split(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!newstr)
		return (backup = NULL, NULL);
	temp = newstr;
	backup = leftovers(temp);
	if (!backup)
	{
		free(backup);
		backup = NULL;
		return (free(temp), temp = NULL, NULL);
	}
	else if (backup[0] == '&')
	{
		free(backup);
		backup = NULL;
	}
	else if (backup != 0)
	{
		newstr = NULL;
		newstr = extract(temp);
		free(temp);
		temp = NULL;
		if (!newstr)
			return (free(backup), backup = NULL, NULL);
	}
	return (newstr);
}
