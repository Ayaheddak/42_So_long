/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:00:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 13:06:26 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int render_next_frame(t_param *param)
{
	mlx_hook(param->win_ptr, 2, 0, key_pressed, param);
	mlx_hook(param->win_ptr, 17, 0, ft_exit, NULL);
/*
	gameplay logic
	get key pressed
	swap accordingly
*/
	//game(param);
	draw_map(param);//rendering 
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.img, 0, 0);
	return 0;
}
int main(int ac, char *av[])
{
	t_param	param;

	int		i = 0;
	int		j;
	int		fd;

	if (ac != 2)
	{
		my_putstr("ERROR : Number of arguments\n");
		exit(1);
	}
	fd = open(av[1], O_RDWR);
	param.str = read_map(fd, av[1]);
	get_map(&param);
	// while(param.map[i])
	// {
	// 	printf("%s\n", param.map[i]);
	// 	i++;
	// }
	//param.width = get_rect(&param);
	//param.height = get_rect(&param);
	//printf("%d\n", param.width);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.width * TILESIZE, param.height * TILESIZE, "so_long");
	
	param.img.img = mlx_new_image(param.mlx_ptr, param.width * TILESIZE, param.height * TILESIZE);
	param.img.addr = mlx_get_data_addr(param.img.img, &param.img.bits_per_pixel, &param.img.line_length, &param.img.endian);
	get_textures(&param);
	mlx_loop_hook(param.mlx_ptr, render_next_frame, &param);
	mlx_loop(param.mlx_ptr);
}