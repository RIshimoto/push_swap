#include "../../includes/get_next_line.h"

static char			*ft_getchr(char *buf, char c)
{
	while (*buf != '\0')
	{
		if (*buf == c)
			return (buf);
		buf++;
	}
	return (buf);
}

static char			*ft_strmerge(char const *s1, char const *s2, size_t s2_len)
{
	size_t		merge_len;
	size_t		s1_len;
	char		*str;
	size_t		index;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	merge_len = s1_len + s2_len;
	if (!(str = malloc((merge_len + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	i = 0;
	while (i < s1_len)
		str[index++] = s1[i++];
	i = 0;
	while (i < s2_len)
		str[index++] = s2[i++];
	str[index] = '\0';
	return (str);
}

static int			get_line(char **buf, char **line, int fd)
{
	char	*p;
	int		len;

	p = ft_getchr(*buf, '\n');
	if (!(*line = ft_strmerge(*line, *buf, p - *buf)))
		return (ERROR);
	if (*p == '\n')
	{
		*buf = ft_memmove(*buf, p + 1, ft_getchr(p + 1, '\0') - p);
		return (SUCESS);
	}
	if ((len = read(fd, *buf, BUFFER_SIZE)) < 0)
		return (ERROR);
	(*buf)[len] = '\0';
	return (len == 0 ? END : get_line(buf, line,fd));
}

int					get_next_line(int fd, char **line)
{
	static char	*buf;
	int			result;

	if (!(*line = (char *)malloc(1)))
		return (ERROR);
	*line[0] = '\0';
	if (!buf && !(buf = malloc((BUFFER_SIZE+ 1) * sizeof(char))))
		return (ERROR);
	if ((result = get_line(&buf, line,fd)) != SUCESS)
	{
		free(buf);
		buf = NULL;
	}
	return (result);
}

