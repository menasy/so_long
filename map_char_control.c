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

void	ft_wall_checker(t_map *dt)
{
	dt->i = -1;
	dt->j = 0;
	dt->line_len = ft_strlen(dt->str[0]);
	while (++dt->i < dt->line_count)
		if (dt->line_len != (int)ft_strlen(dt->str[dt->i]))
			ft_error_1("Map is not rectangular", dt);
	dt->i = 0;
	while (dt->j < dt->line_len -1)
	{
		if (dt->str[dt->i][dt->j] == '1'
			&& dt->str[dt->line_count - 1][dt->j] == '1')
			dt->j++;
		else
			ft_error_1("The map is not surrounded by walls", dt);
	}
	while (dt->i < dt->line_count)
	{
		if (dt->str[dt->i][0] == '1' && dt->str[dt->i][dt->line_len - 2] == '1')
			dt->i++;
		else
			ft_error_1("The map is not surrounded by walls !", dt);
	}
}

void	ft_write_map(t_map *dt)
{
	int	i;

	i = 0;
	dt->almp = malloc(sizeof(char) * (dt->line_len * dt->line_count) + 1);
	if (dt->almp == NULL)
		ft_error_2("Memory error !", dt);
	ft_memset(dt->almp, 0, sizeof(char) * (dt->line_len * dt->line_count) + 1);
	while (i < dt->line_count)
	{
		ft_strlcat(dt->almp, dt->str[i], (dt->line_len * dt->line_count) + 1);
		i++;
	}
	if (dt->line_count >= 23 || dt->line_len >= 42)
		ft_error_2("Error: Map is so long !", dt);
}

void	ft_char_checker(t_map *dt)
{
	dt->i = 0;
	dt->i = dt->i + dt->line_len;
	while (dt->i < dt->line_len * dt->line_count)
	{
		if (dt->almp[dt->i] == '1' || dt->almp[dt->i] == '0'
			|| dt->almp[dt->i] == '\n')
		{
			if ((dt->i++ == dt->line_len * dt->line_count -1)
				&& (dt->c == 0 || dt->p == 0 || dt->e == 0))
				ft_error_2("Missing character in the map", dt);
		}
		else if ((dt->almp[dt->i] == 'P' && dt->p == 0)
			|| (dt->almp[dt->i] == 'E' && dt->e == 0))
		{
			if (dt->almp[dt->i] == 'P')
				dt->p = 1;
			if (dt->almp[dt->i++] == 'E')
				dt->e = 1;
		}
		else if (dt->almp[dt->i++] == 'C')
			dt->c++;
		else
			ft_error_2("invalid character in the map", dt);
	}
}

void	ft_flood_fill(int y, int x, t_map *dt)
{
	if (dt->cpystr[y][x] == '1')
		return ;
	dt->cpystr[y][x] = '1';
	ft_flood_fill(y +1, x, dt);
	ft_flood_fill(y -1, x, dt);
	ft_flood_fill(y, x +1, dt);
	ft_flood_fill(y, x -1, dt);
}

void	ft_flood_fill_check(t_map *dt)
{
	dt->i = 0;
	while (dt->i < dt->line_count)
	{
		dt->j = 0;
		while (dt->j < dt->line_len -1)
		{
			if (dt->cpystr[dt->i][dt->j] == 'C'
				|| dt->cpystr[dt->i][dt->j] == 'E' )
				ft_error_2("Error: Unreachable items on the map !", dt);
			else
				dt->j++;
		}
		dt->i++;
	}
}
