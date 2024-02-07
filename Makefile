NAME = so_long
SRCS = so_long.c map_char_control.c map_close_utils.c map_create.c map_first_utils.c movement.c error_utils.c \
 		gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
MINILIBX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@make -C ./libft -s
	@make -C ./mlx &> /dev/null
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME)
	@echo "\033[33m                    __                 "
	@echo "\033[33m   _________       / /___  ____  ____ _"
	@echo "\033[33m  / ___/ __ \     / / __ \/ __ \/ __ \`/"
	@echo "\033[34m (__  ) /_/ /    / / /_/ / / / / /_/ / "
	@echo "\033[34m/____/\____/____/_/\____/_/ /_/\__, /  "
	@echo "\033[34m          /_____/             /____/   "
	@echo "\033[0m"
	@echo "The game is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft clean -s
	@rm -rf $(OBJS) so_long.dSYM -s
	@echo "Object files removed!"

fclean: clean
	@make -C ./libft fclean -s
	@make -C ./mlx clean -s
	@rm -rf $(NAME) -s
	@echo "The game is removed!"

re: fclean all

.PHONY: all clean fclean re
