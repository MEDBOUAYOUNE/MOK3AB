

#include "includes/cub3d.h"

static void	free_func(char **splited, int j)
{
	while (j--)
		free(splited[j]);
	free(splited);
}

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nbr++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nbr);
}

static void	alloc_words(char const *s, char c, char **splited, int words)
{
	size_t	len;
	int		start;
	int		j;

	j = -1;
	start = 0;
	while (++j < words)
	{
		len = 0;
		while (s[start] && s[start] == c)
			start++;
		while (s[start] && s[start] != c)
		{
			start++;
			len++;
		}
		splited[j] = ft_substr(s, start - len, len);
		if (!splited[j])
			free_func(splited, j);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		nbr_word;

	if (!s)
		return (NULL);
	nbr_word = count_words(s, c);
	splited = malloc(sizeof(char *) * (nbr_word + 1));
	if (!splited)
		return (NULL);
	alloc_words(s, c, splited, nbr_word);
	splited[nbr_word] = NULL;
	return (splited);
}
