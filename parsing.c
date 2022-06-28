/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:10:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 04:54:57 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_error("Error : there's an error in the map\n");
		len += ft_strlen(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
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

void	get_map(t_param *param)
{
	param->map = ft_split(param->str, '\n');
	if (check_elem(param) != 0 || check_wall(param) != 0
		|| get_rect(param) != 0)
		ft_error("Error : there's an error in the map\n");
	pos_plyr(param);
}
