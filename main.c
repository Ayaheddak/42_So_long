/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:03:26 by aheddak           #+#    #+#             */
/*   Updated: 2022/04/12 08:31:21 by aheddak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;
    if (x < 0 || x >= 1000 || y < 0 || y > 1000  )
     return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_square(t_param *param, int x, int y, t_data tex)//texture fblast color
{
    int dx = x;
    int dy = y;
    int pos;
    int col;
    
    col =  tex.addr[pos];
    while(dy < y + TILESIZE)
    {
        dx = x;
        while(dx < x + TILESIZE)
        {
            pos = ((dy - y) * TILESIZE + (dx - x));
            my_mlx_pixel_put(param->img, dx, dy,col);// texture[posx, posy] posx = dx - x posy = dy -y
            dx++;
        }
        dy++;
    }
}

void draw_map(t_param *param, char **map)
{
    int i;
    int j;
    
    i = 0;
    while(map[i])
    {
       j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '0')
                draw_square(param , j * TILESIZE, i *TILESIZE, param->tex[0]);
            // else if (map[i][j] == '1')
            //     draw_square(param , j * TILESIZE, i *TILESIZE, 0x0000FF00);
            // else if (map[i][j] == 'P')
            //     draw_square(param , j * TILESIZE, i *TILESIZE, 0x000000FF);
            // else if (map[i][j] == 'E')
            //     draw_square(param , j * TILESIZE, i *TILESIZE, 0x0000FFFF);
            // else if (map[i][j] == 'C')
            //     draw_square(param , j * TILESIZE, i *TILESIZE, 0x00FFFFFF);
           
           j++;
        }
        i++;
    }
}


int key_pressed(int key,t_param *param)
{
    if (key == 53)
    {
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        exit(0);
    }
    else
        printf("buttuns skhrs!\n");
    
   // printf("%d\n", key);
    return (0);
}

int    ft_exit()
{
    exit(0);
}


int	main()
{
	t_param	param;
    int W;
    int H;

    

    char **map = malloc(sizeof(char *) * 6);
    map[0] = strdup("1111111111111111");
    map[1] = strdup("1000000P000000C1");
    map[2] = strdup("1000000C000C0001");
    map[3] = strdup("1E00000000000001");
    map[4] = strdup("1111111111111111");
    map[5] = NULL;



    W = 16 * TILESIZE;//strlen(map[0]) * TILESIZE;
    H = 5 * TILESIZE;
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, W, H, "first try");
    param.img = malloc(sizeof(t_data));
	param.img->img = mlx_new_image(param.mlx_ptr, W, H);
	param.img->addr =  (unsigned int *)mlx_get_data_addr(param.img->img, &param.img->bits_per_pixel, &param.img->line_length, &param.img->endian);
	// for (int i = 0 ; i < 500; i++) 
    // {
	// 	for (int j = 0 ; j < 500 ; j++) 
	// 	my_mlx_pixel_put(&param.img, i + 250, j + 250, 0x00FF0000);
	// }
     param.tex = malloc(sizeof(t_data) * 6);
        int tst;
        int tst2;
    param.tex[0].img = mlx_xpm_file_to_image(param.mlx_ptr, "./tex/g.xpm", &tst, &tst2);
    param.tex[0].addr =  (unsigned int *)mlx_get_data_addr(param.tex[0].img,
    &param.tex[0].bits_per_pixel, &param.tex[0].line_length, &param.tex[0].endian);
    draw_map(&param , map);
   // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img->img, 0, 0);
	mlx_key_hook(param.win_ptr, key_pressed, &param);//
    mlx_hook(param.win_ptr, 17, 0, ft_exit, NULL);//
	mlx_loop(param.mlx_ptr); 
}