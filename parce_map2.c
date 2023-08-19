/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:58:25 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 15:07:50 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/get_next_line.h"

void    ft_checknewline(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == '\n' && str[i + 1] == '\n')
        {
            printf("map not correct\n");
            exit(1);
        }
        i++;
    }   
}
void     ft_valid(char **map)
{
    int i;
    int j;

    
    i = 1;
    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != ' ' && map[0][j] != '1')
        {
            printf("map not closed\n");
            exit(1);
        }
        j++;
    }
    while (map[i + 1])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == ' ')
            {
                if (map[i - 1][j] != '1' || map[i + 1][j] != '1' || map[i][j - 1] != '1' || map[i][j + 1] != '1')
                {
                    printf("map not closedkk\n");
                    exit(1);
                } 
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != ' ' && map[i][j] != '1')
        {
            printf("map not closed\n");
            exit(1);
        }
        j++;
    }
}
int     ft_correct(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 32)
                return(0);
            j++;
        }    
        i++;
    }
    return(1);    
}