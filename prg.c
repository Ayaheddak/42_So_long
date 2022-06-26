/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:10:31 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/25 09:13:49 by aheddak          ###   ########.fr       */
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
int	check_elem(char **str)
{
	int	i;
	int	j;
	int	c_pyr;
	int	c_col;
	int	c_em_s;
	int	c_wall;
	int	c_exit;

	i = 0;
	c_pyr = 0;
	c_col = 0;
	c_em_s = 0;
	c_wall = 0;
	c_exit = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				c_pyr++;
			else if (str[i][j] == 'C')
				c_col++;
			else if (str[i][j] == 'E')
				c_exit++;
			else if (str[i][j] != '1' && str[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (c_exit == 0 || c_col == 0 || c_pyr != 1)
		return (1);
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1')
				return (1);
			else if ((map[i + 1] == NULL && map[i][j] != '1'))
				return (1);
			else if (map[i][0] != '1')
				return (1);
			else if (map[i][j + 1] == '\0' && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_rect(char **map)
{
	int	i;
	int	j;
	int	w;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		tmp = j;
		if (i == 0)
			w = j;
		if (w != tmp)
			return (1); 
		i++;
	}
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
		ft_error ("Error : no such file\n");
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

char	**get_map(char *map)
{
	char	**gmap;

	gmap = ft_split(map, '\n');
	if (check_elem(gmap) != 0 || check_wall(gmap) != 0 || get_rect(gmap) != 0)
		ft_error("Error 1\n");
	return (gmap);
}

int main(int ac , char *av[])
{
  int fd = open(av[1], O_RDWR);
	//  
// if (fd == 0)
// 		ft_error("Error : no such file or directory\n");
  char **map;
  map = get_map(read_map(fd, av[1]));
  printf ("%s", map[3]);
}
// int main (int ac, char *av[])
// {
// 	//printf("%d\n", check_extensionnn(av[1], ".ber"));
// 	printf("%d\n", ft_strcmp(av[1], ".ber"));
// }
// int	ft_error(int i)
// {
// 	// if (i == 1)
// 	// {
// 	// 	write (2, "no such file or directory\n", 26);
// 	// 	exit(1)		
// 	// }
// 	// else if (i == 2)
// 	// {
// 	// 	write (2, "Error on the map\n", 17);
// 	// 	exit(1)
// 	// }
// 	// else
// 	// {
// 	// 	write (2, "Error\n", 6);	
// 	// 	exit(1);
// 	// }
// 	exit(1);
// }