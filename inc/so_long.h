/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include "mlx_linux/mlx.h"
#  define LIB_NAME = "Linux Library"
#		include <X11/X.h>
# else
#  include "mlx_mac/mlx.h"
#  define LIB_NAME = "Mac Library"
# endif

# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_mlx
{
	void		*init;
	void		*wind;
	void		*img;
	void		*plyr;
	void		*empty;
	void		*coin;
	void		*exit;
	void		*wall;
}	t_mlx;

typedef struct s_map
{
	int			fd;
	int			i;
	int			j;
	int			line_len;
	int			line_count;
	char		**str;
	char		**cpystr;
	char		*almp;
	char		*map_dir;
	int			locplyr[2];
	int			locext[2];
	int			p;
	int			c;
	int			e;
	int			move;
	int			longr;
	t_mlx		*sml;
}	t_map;

char	*ft_file_name_check(char *argv, t_map *dt);
int		ft_key_handler_mac(int keycode, t_map *dt);
int		ft_key_handler_linux(int key_code, t_map *dt);
int		ft_map_line_count(t_map *dt);
void	ft_map_read(t_map *dt);
void	ft_wall_checker(t_map *dt);
void	ft_write_map(t_map *dt);
void	ft_char_checker(t_map *dt);
void	ft_open_wind(t_map *dt);
void	ft_put_image(t_map *dt);
void	ft_go_right(t_map *dt);
void	ft_location(t_map *dt);
void	ft_finish(t_map *dt);
void	ft_go_left(t_map *dt);
void	ft_go_up(t_map *dt);
void	ft_go_down(t_map *dt);
void	ft_free(t_map *dt);
int		ft_close_window(t_map *dt);
void	ft_free_mlx(t_map *dt);
void	ft_flood_fill(int x, int y, t_map *dt);
void	ft_flood_fill_check(t_map *dt);
void	ft_error_0(char *s, t_map *dt);
void	ft_error_1(char *s, t_map *dt);
void	ft_error_2(char *s, t_map *dt);
void	ft_error_mesage(char *s, t_map *dt);

#endif
