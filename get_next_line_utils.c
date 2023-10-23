/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:56:55 by gmunoz            #+#    #+#             */
/*   Updated: 2023/10/20 16:50:14 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	int		count;
	int		i;
	char	*cpy;

	count = 0;
	i = 0;
	while (s1[count] != '\0')
		count++;
	cpy = (char *)malloc(count + 1);
	if (!cpy)
		return (NULL);
	while (i < count + 1)
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	newstr = (char *)malloc(i + j + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
