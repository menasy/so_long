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

#include "so_long.h"

void	ft_open_wind(t_map *dt)
{
	int	x;
	int	y;

	dt->sml = malloc(sizeof(t_mlx));
	if (dt->sml == NULL)
		ft_error_mesage("Memmory error", dt);
	dt->sml->init = mlx_init();
	dt->sml->wind = mlx_new_window(dt->sml->init,
			(dt->line_len - 1) * 64, dt->line_count * 64, "so_long");
	dt->sml->plyr = mlx_xpm_file_to_image(dt->sml->init,
			"textures/player", &x, &y);
	dt->sml->empty = mlx_xpm_file_to_image(dt->sml->init,
			"textures/empty", &x, &y);
	dt->sml->coin = mlx_xpm_file_to_image(dt->sml->init,
			"textures/coin", &x, &y);
	dt->sml->exit = mlx_xpm_file_to_image(dt->sml->init,
			"textures/exit", &x, &y);
	dt->sml->wall = mlx_xpm_file_to_image(dt->sml->init,
			"textures/wall", &x, &y);
	if (dt->sml->plyr == NULL || dt->sml->empty == NULL
		|| dt->sml->coin == NULL || dt->sml->exit == NULL
		|| dt->sml->wall == NULL)
		ft_error_mesage("Error: Missing image file !", dt);
	ft_put_image(dt);
}

void	ft_put_image(t_map *dt)
{
	dt->i = -1;
	while (++dt->i < dt->line_count)
	{
		dt->j = -1;
		while (dt->str[dt->i][++dt->j])
		{
			if (dt->str[dt->i][dt->j] == '1')
				mlx_put_image_to_window(dt->sml->init, dt->sml->wind,
					dt->sml->wall, dt->j * 64, dt->i * 64);
			else if (dt->str[dt->i][dt->j] == '0')
				mlx_put_image_to_window(dt->sml->init, dt->sml->wind,
					dt->sml->empty, dt->j * 64, dt->i * 64);
			else if (dt->str[dt->i][dt->j] == 'C')
				mlx_put_image_to_window(dt->sml->init, dt->sml->wind,
					dt->sml->coin, dt->j * 64, dt->i * 64);
			else if (dt->str[dt->i][dt->j] == 'P')
				mlx_put_image_to_window(dt->sml->init, dt->sml->wind,
					dt->sml->plyr, dt->j * 64, dt->i * 64);
			else if (dt->str[dt->i][dt->j] == 'E')
				mlx_put_image_to_window(dt->sml->init, dt->sml->wind,
					dt->sml->exit, dt->j * 64, dt->i * 64);
		}
	}
}

int	ft_key_handler(int key_code, t_map *dt)
{
	if (key_code == 53)
	{
		ft_free_mlx(dt);
		write(1, "Window is closed !\n", 20);
		exit(0);
	}
	if (key_code == 0 || key_code == 123)
		ft_go_left(dt);
	if (key_code == 1 || key_code == 125)
		ft_go_down(dt);
	if (key_code == 2 || key_code == 124)
		ft_go_right(dt);
	if (key_code == 13 || key_code == 126)
		ft_go_up(dt);
	ft_put_image(dt);
	return (0);
}
