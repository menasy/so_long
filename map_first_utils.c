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

char	*ft_file_name_check(char *argv, t_map *dt)
{
	char	*ber;
	char	*map;

	dt->i = 0;
	dt->fd = open(argv, O_RDWR);
	if (dt->fd == -1)
		ft_error_0("Error: No such file or directory", dt);
	dt->j = ft_strlen(argv) -4;
	ber = ft_strdup(".ber");
	map = ft_strdup(argv);
	while (map[dt->j])
	{
		if (map[dt->j++] != ber[dt->i++])
		{
			free(map);
			free(ber);
			ft_error_0("Error: file extension must be '.ber'", dt);
		}
	}
	free(ber);
	return (map);
}

int	ft_map_line_count(t_map *dt)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(dt->fd);
	i++;
	while (str)
	{
		free(str);
		str = get_next_line(dt->fd);
		i++;
	}
	i--;
	close(dt->fd);
	dt->fd = open(dt->map_dir, O_RDWR);
	free(str);
	return (i);
}

void	ft_map_read(t_map *dt)
{
	int	i;

	i = -1;
	dt->str = malloc(sizeof(char *) * (dt->line_count + 1));
	dt->cpystr = malloc(sizeof(char *) * (dt->line_count + 1));
	if (dt->str == NULL || dt->cpystr == NULL)
		ft_error_1("Memory error", dt);
	while (++i < dt->line_count)
		dt->str[i] = get_next_line(dt->fd);
	dt->str[i] = NULL;
	i = -1;
	close(dt->fd);
	dt->fd = open(dt->map_dir, O_RDWR);
	while (++i < dt->line_count)
		dt->cpystr[i] = get_next_line(dt->fd);
	dt->cpystr[i] = NULL;
	close(dt->fd);
	dt->fd = open(dt->map_dir, O_RDWR);
	ft_location(dt);
}

void	ft_location(t_map *dt)
{
	int	i;
	int	j;

	i = -1;
	while (dt->str[++i])
	{
		j = -1;
		while (dt->str[i][++j])
		{
			if (dt->str[i][j] == 'P')
			{
				dt->locplyr[0] = i;
				dt->locplyr[1] = j;
			}
			if (dt->str[i][j] == 'E')
			{
				dt->locext[0] = i;
				dt->locext[1] = j;
			}
		}
	}
}
