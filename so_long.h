/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:03:41 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/25 09:02:09 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef    SO_LONG_H
# define    SO_LONG_H
# include   <mlx.h>
# include   <stdio.h>
# include	<unistd.h>
# include   <stdlib.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<errno.h>
# include	"get_next_line/get_next_line.h"
# define	TILESIZE 64

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strln(const char *s);
char	*ft_strdp(char *s1);
// char 	**get_map(int fd, char *map);
// char 	*read_map(int fd, char *av);


typedef struct	s_tex {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_tex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct  s_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	t_tex	one_tex;
	t_tex	zero_tex;
	t_tex	c_tex;
	t_tex	e_tex;
	t_tex	p_tex;

	char	**map;
	int		height;
	int		width;

	//t_player	*player;

	t_data	*img;
}               t_param;


// typedef struct  s_player
// {
// 	int xpos;
// 	int	ypos;
// 	int collected;
	
// }		t_player;

void	draw_bg(t_data  *data, char **map, t_param params);
void	draw_map(t_data  *data, char **map, t_param params);
void	draw_square(t_data *img, int x, int y, t_tex tex);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_exit(void);
int		key_pressed(int key,t_param *param);
//char	**get_map(char *map);
//int		ft_error(int i);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_data *img, int x, int y, t_tex tex);
void	draw_bg(t_data  *data, char **map, t_param params);
void	draw_map(t_data  *data, char **map, t_param params);

#endif