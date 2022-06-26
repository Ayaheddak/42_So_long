/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:00:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 05:06:56 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// // int	main(int ac, char *av[])
// // {
// // 	t_param param;
// // 	t_data  img;
// // 	char **map;
// //     char *str;
// //     int fd;

// // 	if(ac != 2)
// // 	{
// // 		my_putstr("ERROR : Number of arguments\n");
// // 		exit(1);
// // 	}
// //     fd = open(av[1], O_RDWR);
// //     str = read_map(fd,av[1]);
// //     map = get_map(str);
// //     param.mlx_ptr = mlx_init();
// // 	// get map hieght replace with 5
// // 	// get map width replace with 16
// //     param.win_ptr = mlx_new_window(param.mlx_ptr, 16 * TILESIZE, 5 * TILESIZE, "first try");//h * tilesize and l * tilesize
// //     img.img = mlx_new_image(param.mlx_ptr, 16 * TILESIZE, 5 * TILESIZE);
// //     img.addr =  mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);// to get information related to the image
// //     //img.bits_per_pixel == kayarf rir bits so khsu yearrf chhal mn bits kayn f dik pixeel
// //     //&img.line_length hit howa kayerf rir 1d so kaychof rir tableau d 1D khsu yearf chhal lenghth loli
// //     //img.endian wach pc kayqra mn loli lakhri or leaks
// //     get_textures(&param);
// //     // draw_map(&img, map, param);
// //     draw_bg(&img, map, param);
// //     mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
// //     draw_map(&img, map, param);
// // 	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
// //     mlx_key_hook(param.win_ptr, key_pressed, &param);
// //     mlx_hook(param.win_ptr, 17, 0, ft_exit, NULL);//
// // 	mlx_hook(param.win_ptr, 2, 0, key_pressed, &param);//
// //     //mlx_loop_hook(param.mlx_ptr, update, NULL);
// //     mlx_loop(param.mlx_ptr);
// // }
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

int main(int ac, char *av[])
{
    t_param param;
    t_data  img;
    char **map;
    char *str;
    int fd;

	if(ac != 2)
	{
		my_putstr("ERROR : Number of arguments\n");
		exit(1);
	}
    fd = open(av[1], O_RDWR);
    str = read_map(fd,av[1]);
    map = get_map( str);
    param.mlx_ptr = mlx_init();
    param.win_ptr = mlx_new_window(param.mlx_ptr, 16 * TILESIZE, 5 * TILESIZE, "first try");//h * tilesize and l * tilesize
    img.img = mlx_new_image(param.mlx_ptr,16*TILESIZE, 5*TILESIZE);
    img.addr =  mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);// to get information related to the image
    //img.bits_per_pixel == kayarf rir bits so khsu yearrf chhal mn bits kayn f dik pixeel
    //&img.line_length hit howa kayerf rir 1d so kaychof rir tableau d 1D khsu yearf chhal lenghth loli
    //img.endian wach pc kayqra mn loli lakhri or leaks
    get_textures(&param);
    // draw_map(&img, map, param);
    draw_bg(&img, map, param);
    mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
    draw_map(&img, map, param);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img.img, 0, 0);//img.img f
    mlx_key_hook(param.win_ptr, key_pressed, &param);
    mlx_hook(param.win_ptr, 17, 0, ft_exit, NULL);//
    mlx_loop(param.mlx_ptr);
}