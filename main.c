
#include "includes/cub3d.h"



// void render_line(t_var *var)
// {
//     int i = 0;

//     while ((var->player_y * GRID) - i > 0)
//     {
//         if (var->map[(int)(((var->player_y * GRID) - i) / GRID)][(int)var->player_x] == '1')
//             break;
//         my_mlx_pixel_put(var->d, var->player_x * GRID, (var->player_y * GRID) - i, 16711890);
//         i++;
//     }
// }

void draw_rays(t_var *var)
{
//     // var->angle = 0;
//     int i = 0;
// while (i < 60)
// {

        double new_x = var->player_x * GRID;
        double new_y = var->player_y * GRID;
        while ((new_x >= 0 && new_x < (var->row_n * GRID)) && (new_y >= 0 && new_y < (var->column_n * GRID)))
        {
            if (var->map[(int)(new_y / GRID)][(int)(new_x/ GRID)] == '1')
                break;
            my_mlx_pixel_put(var->d, new_x, new_y, 5375);

            new_x += cos(var->angle);
            new_y += sin(var->angle);
        }
//         var->angle += (PI / 180);
//         i++;
// }
}


int check_territory(t_var *var, double i, double j, int op)
{
    if (op == 1)
    {
        var->check_x = (int)(var->player_x + j);
        var->check_y = (int)(var->player_y + i);
        if (var->map[var->check_y][var->check_x] == '1')
            return 1;
        return 0;
    }
    else
    {
        var->check_x = (int)(var->player_x - j);
        var->check_y = (int)(var->player_y - i);
        if (var->map[var->check_y][var->check_x] == '1')
            return 1;
        return 0;
    }
}


void    move_stop(t_var *var)
{
    if (var->player_mv == 97)
        if (!check_territory(var, 0, MOV, -1))
        {
            var->player_x += MOV + cos(var->angle + PI / 2);
            var->player_y += MOV - sin(var->angle + PI / 2);
        }
    if (var->player_mv == 100)
        if (!check_territory(var, 0, MOV, 1))
        {
            var->player_x +=(MOV);
            // var->player_y += cos(var->angle);
        }
    if (var->player_mv == 119)
        if (!check_territory(var, MOV, 0, -1))
            var->player_y -= (MOV);
    if (var->player_mv == 115)
        if (!check_territory(var, MOV, 0, 1))
            var->player_y +=(MOV);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(int ac, char **av)
{
    int fd;
    t_var *var;
    t_mlx   *ref;


	if (ac > 2 || ac == 1)
		ft_putstr("you should pass just 2 argument");
	else if (ac == 2)
    {
        var = malloc(sizeof(t_var));
        var->d = malloc(sizeof(t_data));
        ref = malloc(sizeof(t_mlx));
        var->ref = ref;
        //must be freed
        ft_check(av[1]);
        fd = open(av[1], O_RDONLY);
        parce_check(fd, var);
        ref->mlx = mlx_init();
        ref->mlx_win = mlx_new_window(ref->mlx, H_SCREEN, W_SCREEN, "MOKA3AB");
        while (1)
        {
            var->d->img = mlx_new_image(ref->mlx, H_SCREEN, W_SCREEN);
            var->d->addr = mlx_get_data_addr(var->d->img, &var->d->bits_per_pixel, &var->d->line_length,
                                &var->d->endian);

            player_pos(var);
            map_towd(var);
            pixling_player(var);
            // render_line(var);
            draw_rays(var);
            mlx_hook(ref->mlx_win, 02, 1L<<0, ft_esc, ref);
            mlx_hook(ref->mlx_win, 17, 0, ft_close, ref);
            mlx_hook(ref->mlx_win, 02, 1L<<0, key_hook_mov, var);
            mlx_hook(ref->mlx_win, 03, 1L<<0, key_hook_dir, var);
            mlx_put_image_to_window(ref->mlx, ref->mlx_win, var->d->img, 0, 0);
            mlx_loop(ref->mlx);

        }


        }
}

