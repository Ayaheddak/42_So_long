# include "so_long.h"

// map done
// graphic management done
// A = 0 , S = 1 , D = 2, W = 13;
//swap entre P and free space
//else if (map[i][j] == 'P')
//draw_square(data , j * TILESIZE, i *TILESIZE, params.p_tex)
// int  key_pressed(int key , int i , int j)
// {
//     int x = j;
//     int y = i;

//     if(key == 0)
//     {
//        x--;
//     }
//     else if (key == 1)
//     {
//        y--;
//     }
//     else if (key == 2)
//     {
//        x++;
//     }
//     else if (key == 13)
//     {
//        y++;
//     }
// }
// typedef struct s_pos
// {
//     int old_pos_x;
//     int new_pos_y;
//     int pos_x;
//     int pos_y;
//     int show;
//     int movement;

// }               t_pos;

// typedef struct	s_plyr 
// {
// 	int	up;
// 	int	down;
// 	int	left;
// 	int	right;
// }               t_plyr;
// //void get_input()
// move_player()

// void map_update(t_pos *p, char move)
// {
//     p->old_pos_x = p->pos_x;
//     p->old_pos_x = p->pos_x;
// }
// typedef struct s_player
// {
//     int old_pos_x;
//     int old_pos_y;
//     int pos_x;
//     int pos_y;
//     int show;
//     int movement;
// }              t_player;

// void map_update(t_      player *p) 
// {
//     map[p->old_pos_x][p->old_pos_y] -= 1;
//     map[p->pos_x][p->pos_y] += 1;//player pos
// }
// void move_player(struct player *p, char move){
//     //Save current player state
//     p->old_pos_x = p->pos_x;
//     p->old_pos_y = p->pos_y;

//     switch(move) {
//         case 'w':
//             p->pos_x -= 1;
//             break;
//         case 's':
//             p->pos_x += 1;
//             break;
//         case 'd':
//             p->pos_y += 1;
//             break;
//         case 'a':
//             p->pos_y -= 1;
//             break;
//     }
//     //Fit position to map

//     //Rotate right
//     p->pos_x %= 5;
//     p->pos_y %= 5;

//     if (p->pos_x < 0)
//         p->pos_x = 4;
//     if (p->pos_y < 0)
//         p->pos_y = 4;
// }

// void p_show(t_player *p) {
//     //Report Player position
//     printf("Player Position [%d,%d]\n", p->pos_x, p->pos_y);    
// }
// int main(int ac , char *av[])
// {
//   int fd = open(av[1], O_RDWR);
//   if (fd == 0)
//     return (0);
//   char **map;
//   map = get_map(fd, read_map(fd,av[1]));
   
//   printf("%s",map[3]);
// }

 