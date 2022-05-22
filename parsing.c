#include "so_long.h"

int ft_error(int i)
{
    printf("Error !! %d \n",i);
    exit(1);
}
int  check_extension(char *s1, char *s2)//s1 map and s2 .ber
{
    int len1;
    int len2;
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if(len1 <= len2)//another cond ..ber
        return(ft_error(666));
    while(s1[len1] == s2[len2] && len2>0)
    {
        len1--;
        len2--;
    }
   if (s1[len1] != s2[len2])
       return(ft_error(0));
   else
        return(0);
}
int check_elem(char **str)
{
  int i;
  int j;
  int c_pyr;
  int c_col;
  int c_em_s;
  int c_wall;
  int c_exit;
  
  i = 0;
  c_pyr = 0;
  c_col = 0;
  c_em_s = 0;
  c_wall = 0;
  c_exit = 0;
  while(str[i])
  {
    j = 0;
    while(str[i][j])
    { 
      if(str[i][j] == 'P')
        c_pyr++;
      else if(str[i][j] == 'C')
        c_col++;
      else if(str[i][j] == 'E')
        c_exit++;
      else if (str[i][j] != '1' && str[i][j] != '0')
        return (ft_error(55));
      j++;
    }
    i++;
  }
  if(c_exit == 0 || c_col == 0 || c_pyr != 1)//ft att
    return (ft_error(1));
  return (0);
}

 int check_wall(char **map)
{
  int i;
  int j;

  i = 0;
  while(map[i])
  {
    j = 0;
    while(map[i][j])
    {
      if (map[0][j] != '1')
      {
        return (ft_error(2));
      }
      else if (map[i + 1] == NULL && map[i][j] != '1')
      {
        return (ft_error(3));
      } 
      else if (map[i][0] != '1')
      {
        return (ft_error(7));
      }
      else if (map[i][j + 1] == '\0' && map[i][j] != '1')
      {
        return (ft_error(4));
      }
      j++;
    }
    i++;
  }
  return (0);
} 
int get_rect(char **map)
{
  int i;
  int j;
  int w;
  int tmp;

  i = 0;
  tmp = 0;
  if (check_wall(map)!= 0)
   { 
     printf("waa wall fih prb");
     return(ft_error(5));
   } 
  while(map[i])
  {
    j = 0;
    while(map[i][j])
      j++;
    tmp = j;
    if (i == 0)
      w = j;
    if ( w != tmp)
      return(ft_error(6));
      
    i++;
  }
  if (tmp > i)
    return(0);
  else if (tmp == i)
    return(ft_error(777));
  else if(check_elem(map) != 0)
    return (ft_error(10));
  return (1);
}
size_t get_size(int fd, char *av)
{
  char *str;
  size_t len;

  len = 0;
  if(check_extension(av,".ber") != 0)
    return(ft_error(8));
  str = get_next_line(fd);
  if (str == NULL)
    return(ft_error(13));
  while (str != NULL)
  {
    len +=ft_strlen(str);
    str = get_next_line(fd);
  }
  return (len);
}

char *read_map(int fd, char *av)
{
  char *map;
  size_t size;

  size = get_size(fd,av);
  close(fd);
  fd = open(av, O_RDONLY);
  map = malloc(sizeof(char) * (size + 1));
  if (!map)
		return (NULL);
  read(fd, map, size);
  map[size] = '\0';
  return(map);
} 

char **get_map(int fd, char *map)
{
  char **gmap;
  
  gmap = ft_split(map,'\n');
  if(check_elem(gmap) != 0 || check_wall(gmap) != 0 || get_rect(gmap) != 0)//ft att
   return(NULL);
  return(gmap);
}
int main(int ac , char *av[])
{
  int fd = open(av[1], O_RDWR);
  if (fd == 0)
    return (0);
  char **map;
  map = get_map(fd, read_map(fd,av[1]));
   
  printf("%s",map[3]);
}
//cond c'est on a empty line 