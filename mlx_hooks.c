
#include "includes/cub3d.h"

int key_hook_dir(int keycode, t_var *var)
{
    if (keycode == 65361)
    {
        var->angle += DIR;
        if (var->angle > (2 * PI))
            var->angle = 0;
    }
    else if (keycode == 65363)
    {
        var->angle -= DIR;
        if (var->angle < 0)
            var->angle = (2 * PI);
    }
    return (0);
}

int key_hook_mov(int keycode, t_var *var)
{
    if (keycode == 97)
        var->player_mv = 97;
    else if (keycode == 100)
       var->player_mv = 100;
    else if (keycode == 119) 
        var->player_mv = 119;
    else if (keycode == 115) 
        var->player_mv = 115;
    else
        return 0;
    
    move_stop(var);
    map_towd(var);
    pixling_player(var);
    // render_line(var);
    draw_rays(var);
    mlx_put_image_to_window(var->ref->mlx, var->ref->mlx_win, var->d->img, 0, 0);
    
    return (0);
}

int ft_close(t_mlx *ref)
{
    mlx_destroy_window(ref->mlx, ref->mlx_win);
    exit(0);
}
int    ft_esc(int keycode, t_mlx *ref)
{
    if (keycode == 53)
    {
         mlx_destroy_window(ref->mlx, ref->mlx_win);
         exit(0);
    }
    return (0);
}