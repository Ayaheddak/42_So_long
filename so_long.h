/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:03:41 by aheddak           #+#    #+#             */
/*   Updated: 2022/04/12 07:46:23 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef    SO_LONG_H
# define    SO_LONG_H
# include   <mlx.h>
# include   <stdio.h>
# include   <stdlib.h>
# include	<string.h>



#define TILESIZE 64


typedef struct  s_data {
	void			*img;
	unsigned  int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}               t_data;

typedef struct  s_param{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
	t_data	*tex;
}               t_param;


#endif
