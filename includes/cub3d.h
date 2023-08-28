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
#include <math.h>
#include "../gnl/get_next_line.h"

#define H_SCREEN 1080
#define W_SCREEN 1080
#define PI	3.14159265
#define GRID 50
#define MOV	0.05
#define DIR  0.1
#define RED_PLAYER 7

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

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_var
{
	char **map;
	int row_n;
	int	column_n;
	double player_x;
	double	player_y;
	double angle;
	int player_mv;
	int check_x;
	int check_y;
	t_data *d;
	t_mlx	*ref;
}	t_var;



//ray
void map_towd(t_var *var);
void pixling_sqr(t_var *var, int i, int j, int color);
void    wh_ofmap(t_var *var);
void    pixling_player(t_var *var);
void    player_pos(t_var *var);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    move_stop(t_var *var);


//test
 void           draw_rays(t_var *var);
 void           render_line(t_var *var);


int key_hook_dir(int keycode, t_var *var);
int key_hook_mov(int keycode, t_var *var);
int ft_close(t_mlx *ref);
int    ft_esc(int keycode, t_mlx *ref);

// parse

void    parce_check(int fd, t_var *var);
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