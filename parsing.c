/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:10:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/26 07:39:37 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	check_elem(t_param *param)
{
	int	i;
	int	j;
	int	c_pyr;
	int	c_em_s;
	int	c_wall;
	int	c_exit;
	
	i = 0;
	c_pyr = 0;
	param->colcount = 0;
	c_em_s = 0;
	c_wall = 0;
	c_exit = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'P')
				c_pyr++;
			else if (param->map[i][j] == 'C')
				param->colcount++;
			else if (param->map[i][j] == 'E')
				c_exit++;
			else if (param->map[i][j] != '1' && param->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (c_exit == 0 || param->colcount == 0 || c_pyr != 1)
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
// int	get_rect(char **map, int nb)
// {
// 	int	i;
// 	int	j;
// 	int	w;
// 	int	tmp;

// 	i = 0;
// 	tmp = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 			j++;
// 		tmp = j;
// 		if (i == 0)
// 			w = j;
// 		if (w != tmp)
// 			return (1); 
// 		i++;
// 	}
// 	if (nb == 1)
// 		return (i);
// 	else if (nb == 2)
// 		return (w);
// 	else
// 		return (0);
// }
int	get_rect(t_param *param)
{
	int	i;
	int	j;
	int	w;
	int	tmp;

	i = 0;
	tmp = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
			j++;
		tmp = j;
		if (i == 0)
			w = j;
		if (w != tmp)
			return (1);
		i++;
	}
	param->height = i;
	param->width = tmp;
	return (0);
}

int	ft_error(char *str)
{
	my_putstr(str);
	exit(1);
}

int	check_extension(char *s1, const char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	if (len <= 4)
		ft_error ("Error : in argument\n");
	len -= 4;
	while (s2[i] && s2[i] == s1[len])
	{
		i++;
		len++;
	}
	if (s2[i] == '\0')
		return (0);
	return (1);
}

size_t	get_size(int fd, char *av)
{
	char	*str;
	size_t	len;

	len = 0;
	if (check_extension(av, ".ber") == 1)
		ft_error ("Error : map file should have .ber\n");
	str = get_next_line(fd);
	if (str == NULL)
		ft_error ("Error : no such file or directory\n");
	while (str != NULL)
	{
		if (*str == '\n')
			ft_error("Error 2\n");
		len += ft_strlen(str);
		str = get_next_line(fd);
	}
	return (len);
}

char	*read_map(int fd, char *av)
{
	char	*map;
	size_t	size;

	size = get_size(fd, av);
	close (fd);
	fd = open(av, O_RDONLY);
	map = malloc(sizeof(char) * (size + 1));
	if (!map)
		return (NULL);
	read (fd, map, size);
	map[size] = '\0';
	return (map);
}

// char	**get_map(t_param *param)
// {
// 	param->map = ft_split(param->str, '\n');
// 	if (check_elem(param->map, param) != 0 || check_wall(param->map) != 0 || get_rect(param) != 0)
// 		ft_error("Error 1\n");
// 	return (NULL);
// }
// void	get_map(t_param *param)
// {
// 	param->map = ft_split(param->str, '\n');
// 	if (check_elem(param->map, param) != 0 || check_wall(param->map) != 0 || get_rect(param) != 0)
// 		ft_error("Error 1\n");
// 	//return (NULL);
// }
void	get_map(t_param *param)
{
	//char **gmap;
	
	param->map= ft_split(param->str, '\n');
	if (check_elem(param) != 0 || check_wall(param) != 0 || get_rect(param) != 0)
		ft_error("Error \n");
	//return (NULL);
}