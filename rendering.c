/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:36:51 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 06:06:53 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *img, int x, int y, t_tex tex)
{
	int	i;
	int	j;
	unsigned int	pos;

	i = x;
	j = y;
	while (j < y + TILESIZE)
	{
		i = x;
		while (i < x +TILESIZE)
		{
			pos = ((j - y) * TILESIZE + (i - x));
			if (((tex.addr[pos] >> 24) & 0xFF) == 0x00)//
				my_mlx_pixel_put(img, i, j, tex.addr[pos]);
			i++;
		}
		j++;
	}
}

void	draw_bg(t_param *param)
{
	int	i;
	int	j;

    i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] != '0' && param->map[i][j] != '1')
				draw_square(&param->img, j * TILESIZE, i * TILESIZE, param->zero_tex);
			j++;
		}
		i++;
	}
}

void	draw_map(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == '0')
				draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->zero_tex);
			else if (param->map[i][j] == '1')
				draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->one_tex);
			else 
			{
				draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->zero_tex);
				if (param->map[i][j] == 'P')
					draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->p_tex);
				else if (param->map[i][j] == 'E')
					draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->e_tex);
				else if (param->map[i][j] == 'C')
					draw_square(&param->img , j * TILESIZE, i * TILESIZE, param->c_tex);
			}
			j++;
		}
		i++;
	}
}