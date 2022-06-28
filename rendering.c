/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:36:51 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 04:38:57 by aheddak          ###   ########.fr       */
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
	int				i;
	int				j;
	unsigned int	pos;

	i = x;
	j = y;
	while (j < y + TS)
	{
		i = x;
		while (i < x + TS)
		{
			pos = ((j - y) * TS + (i - x));
			if (((tex.addr[pos] >> 24) & 0xFF) == 0x00)
				my_mlx_pixel_put(img, i, j, tex.addr[pos]);
			i++;
		}
		j++;
	}
}

void	draw_element(t_param *param, char c, int i, int j)
{
	draw_square(&param->img, j * TS, i * TS, param->zero_tex);
	if (c == '1')
		draw_square(&param->img, j * TS, i * TS, param->one_tex);
	else if (c == 'P')
		draw_square(&param->img, j * TS, i * TS, param->p_tex);
	else if (c == 'E')
		draw_square(&param->img, j * TS, i * TS, param->e_tex);
	else if (c == 'C')
		draw_square(&param->img, j * TS, i * TS, param->c_tex);
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
			draw_element(param, param->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
