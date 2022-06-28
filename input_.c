/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:50:33 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 05:45:13 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_param *param)
{
	if (key == 53)
		ft_exit();
	else if (key == UPBUTTON)
		ft_move_ply_up(param);
	else if (key == DOWNBUTTON)
		ft_move_ply_down(param);
	else if (key == LEFTBUTTON)
		ft_move_ply_left(param);
	else if (key == RIGHTBUTTON)
		ft_move_ply_right(param);
	else
		return (0);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}
