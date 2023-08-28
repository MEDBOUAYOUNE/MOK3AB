#include "includes/cub3d.h"

void    player_pos(t_var *var)
{
    int i = 0;
    int j;

    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
        {
            if (var->map[i][j] == 'N' || var->map[i][j] == 'S' || var->map[i][j] == 'E' || var->map[i][j] == 'W')
            {
                var->player_x = j;
                var->player_y = i;
                if (var->map[i][j] == 'N')
                    var->angle = PI / 2;
                if (var->map[i][j] == 'S')
                    var->angle = (3 * PI) / 2;
                if (var->map[i][j] == 'E')
                    var->angle = 0;
                if (var->map[i][j] == 'W')
                    var->angle = PI;
                return;
            }
            j++;
        }
        i++;
    }
}
void    pixling_player(t_var *var)
{
    int j;
    int i;


    double x = var->player_x * GRID;
    double y = var->player_y * GRID;
    i = y - RED_PLAYER;
    while (i <= y + RED_PLAYER) 
    {
        j = x - RED_PLAYER;
        while ( j <= x + RED_PLAYER)
        {
            double dx = j - x;
            double dy = i - y;
            if (pow(dx, 2.0) + pow(dy, 2.0) <= pow(RED_PLAYER, 2.0))
                my_mlx_pixel_put(var->d, j, i, 167168100);
            j++;
        }
        i++;
    }
}

void    wh_ofmap(t_var *var)
{
    int i = 0;
   int j = 0;
    while (var->map[i][j])
        j++;
    var->row_n = j;
    while (var->map[i])
        i++;
    var->column_n = i;
}

void pixling_sqr(t_var *var, int i, int j, int color)
{
    int index = 0;
    int jindex = 0;
    int x_start = j * GRID;
    int y_start = i * GRID;
    
    while (index < GRID)
    {
        jindex = 0;
        while (jindex < GRID)
        {
            if (jindex == 0 && index == 0)
                my_mlx_pixel_put(var->d, x_start + jindex , y_start + index, color);
            else if (index == GRID - 1)
                my_mlx_pixel_put(var->d, x_start + jindex, (y_start + index), 0);
            else if (jindex == GRID -1)
                my_mlx_pixel_put(var->d, x_start + jindex, (y_start + index), 0);
            else
                my_mlx_pixel_put(var->d, x_start + jindex, (y_start + index), color);
            jindex++;
        }
        index++;
    }
}

void map_towd(t_var *var)
{
    int i = 0;
    int j = 0;
    wh_ofmap(var);
    while (i < var->column_n)
    {
        j = 0;
        while (j < var->row_n)
        {
            if (var->map[i][j] == '1')
            {
                pixling_sqr(var, i, j, 16777215);
            }
            else
                 pixling_sqr(var, i, j, 0);
            j++;
        }
        i++;
    }
}