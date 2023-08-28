/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:20:48 by aaouassa          #+#    #+#             */
/*   Updated: 2023/07/21 14:58:54 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    parce_check(int fd, t_var *var)
{
    int i;
    int x;
    int len;
    char    *str;
    char *s;

    x = 0;
    i = 0;
    s = calloc(1, 1);
    while (1)
    {
        i = 0;
        str = get_next_line(fd);
        if (str == NULL)
                break;
        if(x < 6)
        {
            len = ft_strlen(str);
            while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                i++;
            if (str[i] == '\n')
                continue ;
            first_check(str, &x);
            if (x <= 4)
                seconde_check(str, i, len);
            if (x > 4)
                third_check(str);
        }
        else if (x >= 6)
            s = ft_strjoin(s ,str);
    }
    ft_checknewline(s);
    var->map = ft_split(s, '\n');
    if (ft_correct(var->map) == 0)
    {
        printf("invalid map\n");
        exit(1);
    }
    else 
        ft_valid(var->map);
}

void   ft_check(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
   if (i >= 4 && (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' || str[i - 3] != '.'))
   {
        printf("ERROR\n");
        exit(1);
   }
}


