/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:29:32 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 04:31:42 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image_file(t_param *params, char *path, t_tex *texture)
{
	int	w;
	int	h;

	texture->img = mlx_xpm_file_to_image(params->mlx_ptr, path, &w, &h);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length,
			&texture->endian);
}

void	init_textures(t_param *params)
{
	get_image_file(params, "grf/wall.xpm", &params->one_tex);
	get_image_file(params, "grf/free_space.xpm", &params->zero_tex);
	get_image_file(params, "tex/e.xpm", &params->e_tex);
	get_image_file(params, "tex/c.xpm", &params->c_tex);
	get_image_file(params, "tex/p.xpm", &params->p_tex);
}

void	init_window(t_param *param)
{
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->width * TS,
			param->height * TS, "so_long");
	param->img.img = mlx_new_image(param->mlx_ptr, param->width * TS,
			param->height * TS);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel,
			&param->img.line_length,
			&param->img.endian);
}

void	init_map(t_param *param, char	**av)
{
	int		fd;

	fd = open(av[1], O_RDWR);
	param->player = malloc (sizeof(t_plyr));
	param->str = read_map(fd, av[1]);
	get_map(param);
	free(param->str);
	close(fd);
}
