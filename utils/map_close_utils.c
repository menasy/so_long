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

#include "../inc/so_long.h"

void	ft_free(t_map *dt)
{
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->str[dt->i]);
	free(dt->str);
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->cpystr[dt->i]);
	free(dt->cpystr);
	free(dt->map_dir);
	free(dt->almp);
	free(dt->sml);
	free(dt);
}

int	ft_close_window(t_map *dt)
{
	ft_free_mlx(dt);
	write(1, "Window is closed\n", 18);
	exit(0);
}

void	ft_finish(t_map *dt)
{
	ft_free_mlx(dt);
	write (1, "	🎉 🥳 Congratulations you won the game ! 🥳 🎉 \n", 58);
	exit(0);
}

void	ft_free_mlx(t_map *dt)
{
	mlx_destroy_image(dt->sml->init, dt->sml->empty);
	mlx_destroy_image(dt->sml->init, dt->sml->plyr);
	mlx_destroy_image(dt->sml->init, dt->sml->coin);
	mlx_destroy_image(dt->sml->init, dt->sml->wall);
	mlx_destroy_image(dt->sml->init, dt->sml->exit);
	mlx_destroy_window(dt->sml->init, dt->sml->wind);
	free(dt->sml->init);
	ft_free(dt);
}
