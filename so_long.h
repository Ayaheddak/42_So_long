/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 04:57:18 by aheddak           #+#    #+#             */
/*   Updated: 2022/06/28 07:00:17 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    SO_LONG_H
# define    SO_LONG_H
# include   <mlx.h>
# include   <stdio.h>
# include	<unistd.h>
# include   <stdlib.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	"get_next_line/get_next_line.h"
# define    TS 64//tilesize
# define    UPBUTTON 13
# define    DOWNBUTTON 1
# define    LEFTBUTTON 0
# define    RIGHTBUTTON 2
# define    MOVETIMER 30

typedef struct s_norm
{
	int	c_pyr;
	int	c_em_s;
	int	c_wall;
	int	c_exit;
}				t_norm;

typedef struct s_plyr
{
	int	xpos;
	int	ypos;
	int	move;
}				t_plyr;

typedef struct s_enemy
{
	int		xpos;
	int		ypos;
	int		dir;
	char	type;
}				t_enemy;

typedef struct s_tex
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_tex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;

	t_tex	one_tex;
	t_tex	zero_tex;
	t_tex	c_tex;
	t_tex	e_tex;
	t_tex	p_tex;
	t_tex	h_tex;
	t_tex	v_tex;
	t_data	img;
	t_plyr	*player;
	t_enemy	*enemies;
	int		enemycount;
	char	*str;
	char	**map;
	int		height;
	int		width;
	int		colcount;
	int		move_timer;
}		t_param;

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strln(const char *s);
char	*ft_strdp(char *s1);
void	draw_bg(t_param *param);
void	draw_map(t_param *param);
void	draw_square(t_data *img, int x, int y, t_tex tex);
int		ft_exit(void);
int		key_pressed(int key, t_param *param);
int		my_putstr(char *s);
void	get_map(t_param *param);
char	*read_map(int fd, char *av);
void	draw_square(t_data *img, int x, int y, t_tex tex);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_move_ply_down(t_param *param);
void	ft_move_ply_up(t_param *param);
int		get_rect(t_param *param);
void	ft_move_ply_right(t_param *param);
void	ft_move_ply_left(t_param *param);
void	pos_plyr(t_param *param);
void	init_map(t_param *param, char	**av);
void	init_window(t_param *param);
void	init_textures(t_param *params);
int		ft_error(char *str);
int		check_wall(t_param *param);
int		check_elem(t_param *param);
void	init_enemies(t_param *param);
char	*ft_itoa(int n);
#endif