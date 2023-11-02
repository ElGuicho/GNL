/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:17:15 by gmunoz            #+#    #+#             */
/*   Updated: 2023/11/02 13:52:38 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	char	*line;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	fd4 = open(av[4], O_RDONLY);
	fd5 = open(av[5], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		printf("Dir: %p] final str = %s\n", line, line);
		free (line);
		line = get_next_line(fd2);
		if (!line)
			break ;
		printf("Dir: %p] final str = %s\n", line, line);
		free (line);
		line = get_next_line(fd3);
		if (!line)
			break ;
		printf("Dir: %p] final str = %s\n", line, line);
		free (line);
		line = get_next_line(fd4);
		if (!line)
			break ;
		printf("Dir: %p] final str = %s\n", line, line);
		free (line);
		line = get_next_line(fd5);
		if (!line)
			break ;
		printf("Dir: %p] final str = %s\n", line, line);
		free (line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	printf("end of file");
	system("leaks a.out");
	return (0);
}
