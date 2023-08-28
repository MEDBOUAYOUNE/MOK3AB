/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:57:02 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 15:00:29 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int   first_check(char *str, int *x)
{
    while (*str == ' ' || *str == '\t' ||*str == '\n' )
        str++;
    if(!*str)
        return (2);
    else if (!ft_strncmp(str, "NO", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "SO", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "WE", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "EA", 2))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "F", 1))
    {
        (*x)++;
        return (0);
    }
    else if (!ft_strncmp(str, "C", 1))
    {
        (*x)++;
        return (0);
    }
    else
    {
        printf("ERROR nono\n");
        exit(1);
    }
}
void    seconde_check(char *str, int i, int len)
{
    char *pat;

    while(str[i] == ' ' || str[i] == '\t')
        i++;
    i += 2;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    pat = ft_substr(str, i, len - i);
    // printf("-------------%s\n", pat);
    // int fdd = open(pat, O_RDONLY);
    // if (fdd == -1)
    // {
    //     printf("error path\n");
    //     exit(1);
    // }
}
void     third_check(char *str)
{
    char **rgb;
    t_rgb *var;

    var = malloc(sizeof(t_rgb)); 
    //must be freed.
    // int f = 0;
    // int c = 0;
    int flag = 0;

    while (*str == ' ' || *str == '\t')
        str++;
    if (str[0] == 'C')
        flag = 1;
    str++;
    while (*str == ' ' || *str == '\t')
        str++; 
    rgb = ft_split(str, ',');
    if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255) || (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255) || (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
    {
        printf("ERROR\n");
        exit(1);
    }
    if(!flag)
        var->f = (ft_atoi(rgb[0]) * 65536) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
    else if(flag)
        var->c = (ft_atoi(rgb[0]) * 65536) + (ft_atoi(rgb[1]) * 256) +  ft_atoi(rgb[2]);
}
