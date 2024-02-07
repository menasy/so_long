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

void	ft_error_0(char *s, t_map *dt)
{
	free(dt);
	write (2, s, ft_strlen(s));
	exit(1);
}

void	ft_error_1(char *s, t_map *dt)
{
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->str[dt->i]);
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->cpystr[dt->i]);
	free(dt->str);
	free(dt->cpystr);
	free(dt->map_dir);
	free(dt);
	write (2, s, ft_strlen(s));
	exit(1);
}

void	ft_error_2(char *s, t_map *dt)
{
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->str[dt->i]);
	dt->i = -1;
	while (++dt->i < dt->line_count)
		free(dt->cpystr[dt->i]);
	free(dt->str);
	free(dt->cpystr);
	free(dt->map_dir);
	free(dt->almp);
	free(dt);
	write (2, s, ft_strlen(s));
	exit(1);
}

void	ft_error_mesage(char *s, t_map *dt)
{
	ft_free(dt);
	write (2, s, ft_strlen(s));
	exit(1);
}
