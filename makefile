CC = cc
SRCS = srcs/map_checker.c srcs/map_init.c srcs/so_long.c srcs/utils_checker.c srcs/screen_init.c \
       srcs/handle_keys.c srcs/draw.c srcs/map_checker2.c srcs/utils_mlx.c
LIBFT = libft/libft.a
MINI_LIBX = minilibx-linux/libmlx.a
PRINTF = ft_printf/libftprintf.a
OBJS_DIR = objs/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)
CFLAGS = -Wall -Werror -Wextra -g3
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft -L./minilibx-linux -lmlx -L./ft_printf -lftprintf -lX11 -lXext

$(OBJS_DIR)%.o: srcs/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	$(MAKE) -C libft

$(MINI_LIBX):
	$(MAKE) -C minilibx-linux

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re