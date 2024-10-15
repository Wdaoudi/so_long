CC = cc
SRCS = srcs/map_checker.c srcs/map_init.c srcs/so_long.c
LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
OBJS_DIR = objs/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)
CFLAGS = -Wall -Werror -Wextra -g3
NAME = so_long

all: $(MINI_LIBX) $(LIBFT) $(NAME)

# Crée le dossier objs s'il n'existe pas
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Compile chaque .o dans le dossier objs
$(OBJS_DIR)%.o: srcs/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIB_DIR)

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)
	make clean -C $(MINI_LIBX_DIR)

re: fclean all

.PHONY: all clean fclean re