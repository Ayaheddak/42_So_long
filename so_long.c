/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:00:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 07:03:07 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vertical_enemy(t_param *param, int index)
{
	int		x;
	int		y;
	int		dir;
	char	c;

	y = param->enemies[index].ypos;
	x = param->enemies[index].xpos;
	dir = param->enemies[index].dir;
	c = param->map[y + (1 * dir)][x];
	if (c == '0')
	{
		param->map[y + (1 * dir)][x] = 'V';
		param->map[y][x] = '0';
		param->enemies[index].ypos += (1 * dir);
	}
	else if (c == 'P')
		ft_error("PLAYER MAT LAH IRAHMOU");
	else
		param->enemies[index].dir *= -1;
}

void	horizontal_enemy(t_param *param, int index)
{
	int		x;
	int		y;
	int		dir;
	char	c;

	y = param->enemies[index].ypos;
	x = param->enemies[index].xpos;
	dir = param->enemies[index].dir;
	c = param->map[y][x + (1 * dir)];
	if (c == '0')
	{
		param->map[y][x + (1 * dir)] = 'H';
		param->map[y][x] = '0';
		param->enemies[index].xpos += (1 * dir);
	}
	else if (c == 'P')
		ft_error("PLAYER MAT LAH IRAHMOU");
	else
		param->enemies[index].dir *= -1;
}

void	move_enemies(t_param *param)
{
	int	i;

	param->move_timer--;
	if (param->enemycount <= 0 || param->move_timer > 0)
		return ;
	i = 0;
	while (i < param->enemycount)
	{
		if (param->enemies[i].type == 'H')
			horizontal_enemy(param, i);
		if (param->enemies[i].type == 'V')
			vertical_enemy(param, i);
		i++;
	}
	param->move_timer = MOVETIMER;
}

int	render_next_frame(t_param *param)
{
	char	*steps;

	mlx_hook(param->win_ptr, 2, 0, key_pressed, param);
	mlx_hook(param->win_ptr, 17, 0, ft_exit, NULL);
	move_enemies(param);
	draw_map(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img.img, 0, 0);
	steps = ft_itoa(param->player->move);
	mlx_string_put(param->mlx_ptr, param->win_ptr, (param->width * TS) / 2, 20,
		0x00FFFFFF, steps);
	free(steps);
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
