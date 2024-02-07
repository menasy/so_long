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

void	ft_go_right(t_map *dt)
{
	if (dt->str[dt->locplyr[0]][dt->locplyr[1] + 1] != '1')
	{
		ft_putnbr_fd (dt->move++, 1);
		write(1, " ⏩ \n", 7);
		if (dt->str[dt->locplyr[0]][dt->locplyr[1] + 1] == 'C')
			dt->c--;
		if (dt->str[dt->locplyr[0]][dt->locplyr[1] + 1] == 'E' && dt->c == 0)
			ft_finish(dt);
		if (dt->locplyr[0] == dt->locext[0] && dt->locplyr[1] == dt->locext[1])
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'E';
			ft_put_image(dt);
			dt->locplyr[1]++;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
		else
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = '0';
			dt->locplyr[1]++;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
	}
}

void	ft_go_left(t_map *dt)
{
	if (dt->str[dt->locplyr[0]][dt->locplyr[1] - 1] != '1')
	{
		ft_putnbr_fd (dt->move++, 1);
		write(1, " ⬅️ \n", 10);
		if (dt->str[dt->locplyr[0]][dt->locplyr[1] - 1] == 'C')
			dt->c--;
		if (dt->str[dt->locplyr[0]][dt->locplyr[1] - 1] == 'E' && dt->c == 0)
			ft_finish(dt);
		if (dt->locplyr[0] == dt->locext[0] && dt->locplyr[1] == dt->locext[1])
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'E';
			ft_put_image(dt);
			dt->locplyr[1]--;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
		else
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = '0';
			dt->locplyr[1]--;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
	}
}

void	ft_go_down(t_map *dt)
{
	if (dt->str[dt->locplyr[0] + 1][dt->locplyr[1]] != '1')
	{
		ft_putnbr_fd (dt->move++, 1);
		write(1, " ⬆️ \n", 10);
		if (dt->str[dt->locplyr[0] + 1][dt->locplyr[1]] == 'C')
			dt->c--;
		if (dt->str[dt->locplyr[0] + 1][dt->locplyr[1]] == 'E' && dt->c == 0)
			ft_finish(dt);
		if (dt->locplyr[0] == dt->locext[0] && dt->locplyr[1] == dt->locext[1])
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'E';
			ft_put_image(dt);
			dt->locplyr[0]++;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
		else
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = '0';
			dt->locplyr[0]++;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
	}
}

void	ft_go_up(t_map *dt)
{
	if (dt->str[dt->locplyr[0] - 1][dt->locplyr[1]] != '1')
	{
		ft_putnbr_fd (dt->move++, 1);
		write(1, " ⬆️ \n", 10);
		if (dt->str[dt->locplyr[0] - 1][dt->locplyr[1]] == 'C')
			dt->c--;
		if (dt->str[dt->locplyr[0] - 1][dt->locplyr[1]] == 'E' && dt->c == 0)
			ft_finish(dt);
		if (dt->locplyr[0] == dt->locext[0] && dt->locplyr[1] == dt->locext[1])
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'E';
			ft_put_image(dt);
			dt->locplyr[0]--;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
		else
		{
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = '0';
			dt->locplyr[0]--;
			dt->str[dt->locplyr[0]][dt->locplyr[1]] = 'P';
		}
	}
}
