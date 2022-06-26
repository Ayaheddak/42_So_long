/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:36:51 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/25 08:11:27 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void draw_square(t_data *img, int x, int y, t_tex tex)
// {
//     int i = x;
//     int j = y;
//     unsigned int pos;
 
//     while(j < y + TILESIZE)
//     {
//         i = x;
//         while(i < x +TILESIZE)
//         {
//         pos = ((j - y) * TILESIZE + (i - x));
//         my_mlx_pixel_put(img, i, j, tex.addr[pos]);
//         i++;
//         }
//         j++;
//     }
// }

// void draw_bg(t_data  *data, char **map, t_param params)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while(map[i])
//     {
//        j = 0;
//         while(map[i][j])
//         {
//             // if (map[i][j] == '0')
//             //     draw_square(data , j * TILESIZE, i * TILESIZE, params.zero_tex);
//             if (map[i][j] != '0' && map[i][j] != '1')
//                 draw_square(data , j * TILESIZE, i *TILESIZE, params.zero_tex);
//            j++;
//         }
//         i++;
//     }
// }

// void draw_map(t_data  *data, char **map, t_param params)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while(map[i])
//     {
//        j = 0;
//         while(map[i][j])
//         {
//             if (map[i][j] == '0')
//                 draw_square(data , j * TILESIZE, i * TILESIZE, params.zero_tex);
//             else if (map[i][j] == '1')
//                 draw_square(data , j * TILESIZE, i *TILESIZE, params.one_tex);
//             else if (map[i][j] == 'P')
//                 draw_square(data , j * TILESIZE, i *TILESIZE, params.p_tex);
//             else if (map[i][j] == 'E')
//                 draw_square(data , j * TILESIZE, i *TILESIZE,params.e_tex);
//             else if (map[i][j] == 'C')
//                 draw_square(data , j * TILESIZE, i *TILESIZE,params.c_tex);        
//            j++;
//         }
//         i++;
//     }
// }