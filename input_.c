/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:50:33 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 06:22:22 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_param *param)
{
	if (key == 53)
		ft_exit();
	else if (key == UPBUTTON)
		param->player.dir = UP;
	else if (key == DOWNBUTTON)
		param->player.dir = DOWN;
	else if (key == LEFTBUTTON)
		param->player.dir = LEFT;
	else if (key == RIGHTBUTTON)
		param->player.dir = RIGHT;
	else
		param->player.dir = DEFAULT;
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}