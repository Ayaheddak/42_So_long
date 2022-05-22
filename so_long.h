/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:03:41 by aheddak           #+#    #+#             */
/*   Updated: 2022/05/16 08:13:24 by aheddak          ###   ########.fr       */
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
# include	"get_next_line/get_next_line.h"
# define	TILESIZE 64

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strln(const char *s);
char	*ft_strdp(char *s1);
char **get_map(int fd, char *map);
char *read_map(int fd, char *av);
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
}               t_param;

#endif