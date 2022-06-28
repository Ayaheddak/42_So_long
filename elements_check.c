/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:53:44 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 05:29:04 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	element_counter(t_param *param, t_norm *norm, char c)
{
	if (c == 'P')
		norm->c_pyr++;
	else if (c == 'C')
		param->colcount++;
	else if (c == 'E')
		norm->c_exit++;
	else if (c == 'H' || c == 'V')
		param->enemycount++;
	else if (c != '1' && c != '0')
		ft_error("Error : there's an error in the map\n");
}

int	check_elem(t_param *param)
{
	int		i;
	int		j;
	t_norm	norm;

	i = 0;
	norm.c_pyr = 0;
	param->colcount = 0;
	param->enemycount = 0;
	norm.c_em_s = 0;
	norm.c_wall = 0;
	norm.c_exit = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			element_counter(param, &norm, param->map[i][j]);
			j++;
		}
		i++;
	}
	if (norm.c_exit == 0 || param->colcount == 0 || norm.c_pyr != 1)
		return (1);
	return (0);
}

int	check_wall(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[0][j] != '1')
				return (1);
			else if ((param->map[i + 1] == NULL && param->map[i][j] != '1'))
				return (1);
			else if (param->map[i][0] != '1')
				return (1);
			else if (param->map[i][j + 1] == '\0' && param->map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(char *str)
{
	my_putstr(str);
	exit(1);
}

int	my_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (1);
}
