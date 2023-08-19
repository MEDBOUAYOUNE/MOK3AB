
#include "includes/cub3d.h"
#include "includes/get_next_line.h"

void    pixling_player(t_var *var, t_data d);
int key_hook(int keycode, t_var *var)
{
    if (keycode == 97)
    {
        var->player_x -= 10;
        pixling_player(var, var->dd); 
    }
    else if (keycode == 98)
       var->player_x += 10;
    else if (keycode == 99) 
        var->player_y -= 10;
    else if (keycode == 100) 
        var->player_y += 10;
    return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    player_pos(t_var *var)
{
    int i = 0;
    int j;

    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
        {
            if (var->map[i][j] == 'N' || var->map[i][j] == 'E')
            {
                var->player_x = j;
                var->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
void    pixling_player(t_var *var, t_data d)
{
    int i = 0;
    int j;
    player_pos(var);
    // printf("var->x |%d| var->y |%d|\n", var->player_x, var->player_y);
    while (i < 10) 
    {
        j = 0;
        while ( j < 10)
        {
            my_mlx_pixel_put(&d, var->player_x * var->w_map + j, var->player_y * var->h_map + i, 167168100);
            j++;
        }
        i++;
    }
}

void    wh_ofmap(t_var *var)
{
    var->h_n = 0;
    var->w_n = 0;
    while (var->map[var->h_n][var->w_n])
        var->w_n++;
    var->w_map = W_SCREEN / var->w_n;
    while (var->map[var->h_n])
        var->h_n++;
    var->h_map = H_SCREEN / var->h_n;
}

void pixling_sqr(t_var *var, int i, int j, int color, t_data d)
{
    int index = 0;
    int jindex = 0;
    int x_start = j * var->w_map;
    int y_start = i * var->h_map;
    
    while (index < var->h_map - 1)
    {
        jindex = 0;
        while (jindex < var->w_map - 1)
        {
            if (jindex == 0 || i == 0)
                my_mlx_pixel_put(&d, x_start + jindex , y_start + index, color);
            else
            {
                my_mlx_pixel_put(&d, x_start + jindex, (y_start + index) -1, color);
            }
            jindex++;
        }
        index++;
    }
}

void map_towd(t_var *var, t_data d)
{
    int i = 0;
    int j = 0;
    wh_ofmap(var);
    while (i < var->h_n)
    {
        j = 0;
        while (j < var->w_n)
        {
            if (var->map[i][j] == '0')
            {
                pixling_sqr(var, i, j, 16777215, d);
            }
            else
                 pixling_sqr(var, i, j, 0, d);
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int fd;
    void *mlx;
    void  *mlx_win;
    t_data d;
    t_var *var;


	if (ac > 2 || ac == 1)
		ft_putstr("you should pass just 2 argument");
	else if (ac == 2)
    {
        var = malloc(sizeof(t_var));
        //must be freed
        ft_check(av[1]);
        fd = open(av[1], O_RDONLY);
        parce_check(fd, var);
        mlx = mlx_init();
        mlx_win = mlx_new_window(mlx, H_SCREEN, W_SCREEN, "MOKA3AB");
        d.img = mlx_new_image(mlx, H_SCREEN, W_SCREEN);
        d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length,
                            &d.endian);
        map_towd(var, d);
        pixling_player(var, d);
        mlx_hook(mlx_win, 02, 1, key_hook, NULL);
        mlx_put_image_to_window(mlx, mlx_win, d.img, 0, 0);
        mlx_loop(mlx);
    }


}

