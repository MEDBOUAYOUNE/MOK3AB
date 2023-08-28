

#include "get_next_line.h"

char	*ft_rest(char *rst)
{
	char	*stock;
	int		i;
	int		k;

	i = 0;
	while (rst[i] && rst[i] != '\n')
		i++;
	if (!rst[i])
		return (free_it(rst));
	stock = malloc(sizeof(char) * ((ft_strlen1(rst) - i) + 1));
	if (!stock)
		return (free_it(rst));
	i++;
	k = 0;
	while (rst[i])
	{
		stock[k] = rst[i];
		k++;
		i++;
	}
	stock[k] = '\0';
	free(rst);
	return (stock);
}

char	*ft_line(char *stline)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!ft_strlen1(stline))
		return (NULL);
	while (stline[i] && stline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (stline[j] && j <= i)
	{
		line[j] = stline[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next(int fd, char *stach)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(stach, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(stach);
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		stach = ft_strjoin(stach, buff);
	}
	free(buff);
	return (stach);
}

char	*get_next_line(int fd)
{
	char		*k;
	static char	*h;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	h = get_next(fd, h);
	if (!h)
		return (NULL);
	k = ft_line(h);
	h = ft_rest(h);
	return (k);
}
