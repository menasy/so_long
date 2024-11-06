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

#include "inc/so_long.h"

int	main(int ac, char *argv[])
{
	t_map	*dt;

	dt = malloc(sizeof(t_map));
	if (dt == NULL)
		ft_error_0("Memry error", dt);
	if (ac != 2)
		ft_error_0("invalid argument", dt);
	dt->c = 0;
	dt->e = 0;
	dt->p = 0;
	dt->move = 1;
	dt->map_dir = ft_file_name_check(argv[1], dt);
	dt->line_count = ft_map_line_count(dt);
	ft_map_read(dt);
	ft_wall_checker(dt);
	ft_write_map(dt);
	ft_char_checker(dt);
	ft_flood_fill(dt->locplyr[0], dt->locplyr[1], dt);
	ft_flood_fill_check(dt);
	ft_open_wind(dt);
	system("afplay GameView/FB.mp3 & ps -ax | grep -v grep | grep afplay | awk '{print $1}' > FB.txt");
	# if defined(__APPLE__)
		mlx_hook(dt->sml->wind, 02, 0L, ft_key_handler_mac, dt);
		mlx_hook(dt->sml->wind, 17, 0L, ft_close_window, dt);
	# elif defined(__linux__)
		mlx_key_hook(dt->sml->wind, ft_key_handler_linux, dt);
		mlx_hook(dt->sml->wind, 33, 0L, ft_close_window, dt);
	# endif
	mlx_loop(dt->sml->init);
	return (0);
}
