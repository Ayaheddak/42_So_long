/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:00:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/05/22 20:09:53 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_pressed(int key,t_param *param)
{
    if (key == 53)
    {
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        exit(0);
    }
    else
        printf("buttuns skhrs!\n");
    return (0);
}

int    ft_exit()
{
    exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(t_data *img, int x, int y, t_tex tex)
{
    int i = x;
    int j = y;
    unsigned int pos;
 
    while(j < y + TILESIZE)
    {
        i = x;
        while(i < x +TILESIZE)
        {
        pos = ((j - y) * TILESIZE + (i - x));
        my_mlx_pixel_put(img, i, j, tex.addr[pos]);
        i++;
        }
        j++;
    }
}

void draw_map(t_data  *data, char **map, t_param params)
{
    int i;
    int j;
    
    i = 0;
    while(map[i])
    {
       j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '0')
                draw_square(data , j * TILESIZE, i * TILESIZE, params.zero_tex);
            else if (map[i][j] == '1')
                draw_square(data , j * TILESIZE, i *TILESIZE, params.one_tex);
            else if (map[i][j] == 'P')
                draw_square(data , j * TILESIZE, i *TILESIZE, params.p_tex);
            else if (map[i][j] == 'E')
                draw_square(data , j * TILESIZE, i *TILESIZE,params.e_tex);
            else if (map[i][j] == 'C')
                draw_square(data , j * TILESIZE, i *TILESIZE,params.c_tex);        
           j++;
        }
        i++;
    }
}

void draw_bg(t_data  *data, char **map, t_param params)
{
    int i;
    int j;
    
    i = 0;
    while(map[i])
    {
       j = 0;
        while(map[i][j])
        {
            // if (map[i][j] == '0')
            //     draw_square(data , j * TILESIZE, i * TILESIZE, params.zero_tex);
            if (map[i][j] != '0' && map[i][j] != '1')
                draw_square(data , j * TILESIZE, i *TILESIZE, params.zero_tex);
           j++;
        }
        i++;
    }
}

void get_textures(t_param *params)
{
    int w;
    int h;
    params->one_tex.img = mlx_xpm_file_to_image(params->mlx_ptr, "grf/wall.xpm", &w, &h);
    params->one_tex.addr = ( int *)mlx_get_data_addr(params->one_tex.img, &params->one_tex.bits_per_pixel,
        &params->one_tex.line_length,&params->one_tex.endian);
    
    params->zero_tex.img = mlx_xpm_file_to_image(params->mlx_ptr, "grf/free_space.xpm", &w, &h);
    params->zero_tex.addr = ( int *)mlx_get_data_addr(params->zero_tex.img, &params->zero_tex.bits_per_pixel,
        &params->zero_tex.line_length,&params->zero_tex.endian);
    
    params->e_tex.img = mlx_xpm_file_to_image(params->mlx_ptr, "tex/e.xpm", &w, &h);
    params->e_tex.addr = ( int *)mlx_get_data_addr(params->e_tex.img, &params->e_tex.bits_per_pixel,
        &params->e_tex.line_length,&params->e_tex.endian);
    
    params->c_tex.img = mlx_xpm_file_to_image(params->mlx_ptr, "grf/coll.xpm", &w, &h);
    params->c_tex.addr = ( int *)mlx_get_data_addr(params->c_tex.img, &params->c_tex.bits_per_pixel,
        &params->c_tex.line_length,&params->c_tex.endian);

    params->p_tex.img = mlx_xpm_file_to_image(params->mlx_ptr, "tex/p.xpm", &w, &h);
    params->p_tex.addr = ( int *)mlx_get_data_addr(params->p_tex.img, &params->p_tex.bits_per_pixel,
        &params->p_tex.line_length,&params->p_tex.endian);
}

// int main(int ac, char *av[])
// {
//     t_param param;
//     t_data  img;
//     char **map;
//     char *str;
//     int fd;

//     fd = open(av[1], O_RDWR);
//     str = read_map(fd,av[1]);
//     map = get_map(fd, str);
//     param.mlx_ptr = mlx_init();
//     param.win_ptr = mlx_new_window(param.mlx_ptr, 16 * TILESIZE, 5 * TILESIZE, "first try");//h * tilesize and l * tilesize
//     img.img = mlx_new_image(param.mlx_ptr,16*TILESIZE, 5*TILESIZE);
//     img.addr =  mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);// to get information related to the image
//     //img.bits_per_pixel == kayarf rir bits so khsu yearrf chhal mn bits kayn f dik pixeel
//     //&img.line_length hit howa kayerf rir 1d so kaychof rir tableau d 1D khsu yearf chhal lenghth loli
//     //img.endian wach pc kayqra mn loli lakhri or leaks
//     get_textures(&param);
//     // draw_map(&img, map, param);
//     draw_bg(&img, map, param);
//     mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
//     draw_map(&img, map, param);
// 	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
//     mlx_key_hook(param.win_ptr, key_pressed, &param);
//     mlx_hook(param.win_ptr, 17, 0, ft_exit, NULL);//
//     mlx_loop(param.mlx_ptr);
// }