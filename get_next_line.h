#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(int count, int size);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
