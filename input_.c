/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:50:33 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 04:59:06 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(0);
	}
	else
		printf("buttuns skhrs!\n");
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}