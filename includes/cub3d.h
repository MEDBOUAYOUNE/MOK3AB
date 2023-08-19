/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:21:00 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 15:01:55 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <mlx.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

#define H_SCREEN 800
#define W_SCREEN 800

typedef struct  s_rgb
{
    int f;
    int c;
} t_rgb ;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_var
{
	char **map;
	double	h_map;
	double w_map;
	int h_n;
	int	w_n;
	int player_x;
	int	player_y;
	t_data dd;
}	t_var;


//ray
void    parce_check(int fd, t_var *var);


// parse

int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const	char *s);
void	ft_putstr(char *s);
void   ft_check(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);


int   first_check(char *str, int *x);
void    seconde_check(char *str, int i, int len);
void     third_check(char *str);


void    ft_checknewline(char *str);
void     ft_valid(char **map);
int     ft_correct(char **map);
#endif