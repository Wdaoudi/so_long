CC = cc
SRCS = srcs/map_checker.c srcs/map_init.c srcs/so_long.c srcs/utils_checker.c srcs/screen_init.c \
srcs/handle_keys.c srcs/draw.c 
LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
PRINTF_DIR = ./ft_printf
OBJS_DIR = objs/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)
CFLAGS = -Wall -Werror -Wextra -g3
NAME = so_long

all: $(MINI_LIBX) $(LIBFT) $(PRINTF_DIR)/libftprintf.a $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: srcs/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIB_DIR)

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX) $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -L$(PRINTF_DIR) -lftprintf -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re