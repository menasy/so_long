NAME = so_long
SRCS = so_long.c utils/map_char_control.c utils/map_close_utils.c utils/map_create.c utils/map_first_utils.c \
       utils/movement.c utils/error_utils.c inc/gnl/get_next_line.c inc/gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = inc/libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    LDFLAGS = -Linc/mlx_linux -lmlx -Linc/libft -lft -lX11 -lXext -lm -lbsd
    MINILIBX = inc/mlx_linux/libmlx.a
else ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -Linc/mlx_mac -lmlx -Linc/libft -lft -framework OpenGL -framework AppKit
    MINILIBX = inc/mlx_mac/libmlx.a
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C inc/libft >/dev/null 2>&1
	@make -C $(dir $(MINILIBX)) >/dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME) >/dev/null 2>&1
	@echo "\033[33m                    __                 "
	@echo "\033[33m   _________       / /___  ____  ____ _"
	@echo "\033[33m  / ___/ __ \\     / / __ \\/ __ \\/ __ \`/"
	@echo "\033[34m (__  ) /_/ /    / / /_/ / / / / /_/ / "
	@echo "\033[34m/____/\\____/____/_/\\____/_/ /_/\\__, /  "
	@echo "\033[34m          /_____/             /____/   "
	@echo "\033[0m"
	@echo "\033[32m$(NAME) build complete!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1

clean:
	@make -C inc/libft clean >/dev/null 2>&1
	@rm -rf $(OBJS) so_long.dSYM >/dev/null 2>&1
	@echo "\033[32mObject files cleaned.\033[0m"

fclean: clean
	@make -C inc/libft fclean >/dev/null 2>&1
	@make -C $(dir $(MINILIBX)) clean >/dev/null 2>&1
	@rm -rf $(NAME) >/dev/null 2>&1
	@echo "\n\033[31mEverything deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re
