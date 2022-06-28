/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:00:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 04:50:53 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_param *param)
{
	mlx_hook(param->win_ptr, 2, 0, key_pressed, param);
	mlx_hook(param->win_ptr, 17, 0, ft_exit, NULL);
	draw_map(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img.img, 0, 0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_param	param;

	if (ac != 2)
	{
		my_putstr("Error : Number of arguments\n");
		exit(1);
	}
	init_map(&param, av);
	init_window(&param);
	init_textures(&param);
	mlx_loop_hook(param.mlx_ptr, render_next_frame, &param);
	mlx_loop(param.mlx_ptr);
}
