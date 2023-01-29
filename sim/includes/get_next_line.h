#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFFER_SIZE 1024
#define SUCESS 1
#define END 0
#define ERROR -1

int		get_next_line(int fd, char **line);

#endif
