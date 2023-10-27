/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:55 by gmunoz            #+#    #+#             */
/*   Updated: 2023/10/27 15:20:34 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*total;
	size_t	i;

	i = 0;
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	i = 0;
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
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
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
