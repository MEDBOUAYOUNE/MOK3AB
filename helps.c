/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:23:05 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/20 17:34:22 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*f1;
	unsigned char	*f2;
	int				i;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	i = 0;
	while ((f1[i] || f2[i]))
	{
		if (f1[i] != f2[i])
		{
			return (f1[i] - f2[i]);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	x = 0;
	while ((f1[x] || f2[x]) && x < n)
	{
		if (f1[x] != f2[x])
		{
			return (f1[x] - f2[x]);
		}
		x++;
	}
	return (0);
}

// char	*ft_strdup(const char	*s1)
// {
// 	char	*cpy_s1;
// 	int		s_s;
// 	int		i;

// 	i = 0;
// 	s_s = 0;
// 	while (s1[s_s] != '\0')
// 		s_s++;
// 	cpy_s1 = malloc(s_s * sizeof(char) + 1);
// 	if (!cpy_s1)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		cpy_s1[i] = s1[i];
// 		i++;
// 	}
// 	cpy_s1[i] = '\0';
// 	return (cpy_s1);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;
	//size_t	j;

	if (!s)
		return (NULL);
	//j = 0;
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	while (s[start] && i < len)
	{
		dup[i] = s[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}
int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long long int	rst;

	i = 0;
	neg = 1;
	rst = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (i[str] == '-')
			neg = neg * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		rst = (rst * 10) + (str[i] - '0');
		i++;
	}
	if (LLONG_MAX < rst && neg == 1)
		return (-1);
	else if (LLONG_MAX < rst && neg == -1)
		return (0);
	//printf("here atoi : %llu\n", rst);
	return (neg * rst);
}

