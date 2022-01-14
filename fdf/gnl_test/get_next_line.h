#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include<stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		get_ft_strlen(char	*str);
char	*get_ft_strdup(char *str);
char	*get_ft_strchr(char *s, int c);
char	*get_ft_strjoin(char *s1, char *s2);
#endif
