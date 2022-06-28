/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plyr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 09:39:34 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 03:32:37 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_plyr(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'P')
			{
				param->player->xpos = j;
				param->player->ypos = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_move_ply_left(t_param *param)
{
	int	x;
	int	y;

	x = param->player->xpos;
	y = param->player->ypos;
	if (param->map[y][x - 1] == '0' || param->map[y][x - 1] == 'C')
	{
		if (param->map[y][x - 1] == '0')
		{
			param->map[y][x - 1] = 'P';
			param->map[y][x] = '0';
		}
		if (param->map[y][x - 1] == 'C')
		{
			param->map[y][x - 1] = 'P';
			param->map[y][x] = '0';
			param->colcount--;
		}
		param->player->xpos--;
	}
	if (param->colcount == 0 && param->map[y][x - 1] == 'E')
		exit(0);
}

void	ft_move_ply_right(t_param *param)
{
	int	x;
	int	y;

	x = param->player->xpos;
	y = param->player->ypos;
	if (param->map[y][x + 1] == '0' || param->map[y][x + 1] == 'C')
	{
		if (param->map[y][x + 1] == '0')
		{
			param->map[y][x + 1] = 'P';
			param->map[y][x] = '0';
		}
		if (param->map[y][x + 1] == 'C')
		{
			param->map[y][x + 1] = 'P';
			param->map[y][x] = '0';
			param->colcount--;
		}
		param->player->xpos++;
	}
	if (param->colcount == 0 && param->map[y][x + 1] == 'E')
		exit(0);
}

void	ft_move_ply_up(t_param *param)
{
	int	x;
	int	y;

	x = param->player->xpos;
	y = param->player->ypos;
	if (param->map[y - 1][x] == '0' || param->map[y - 1][x] == 'C')
	{
		if (param->map[y -1][x] == '0')
		{
			param->map[y - 1][x] = 'P';
			param->map[y][x] = '0';
		}
		if (param->map[y - 1][x] == 'C')
		{
			param->map[y - 1][x] = 'P';
			param->map[y][x] = '0';
			param->colcount--;
		}
		param->player->ypos--;
	}
	if (param->colcount == 0 && param->map[y - 1][x] == 'E')
		exit(0);
}

void	ft_move_ply_down(t_param *param)
{
	int	x;
	int	y;

	x = param->player->xpos;
	y = param->player->ypos;
	if (param->map[y + 1][x] == '0' || param->map[y + 1][x] == 'C')
	{
		if (param->map[y + 1][x] == '0')
		{
			param->map[y + 1][x] = 'P';
			param->map[y][x] = '0';
		}
		if (param->map[y + 1][x] == 'C')
		{
			param->map[y + 1][x] = 'P';
			param->map[y][x] = '0';
			param->colcount--;
		}
		param->player->ypos++;
	}
	if (param->colcount == 0 && param->map[y + 1][x] == 'E')
		exit(0);
}
