CC = cc

SRCS =  srcs/map_checker.c  srcs/map_init.c \
	srcs/so_long.c \

LIBFT = libft.a
LIB_DIR = ./libft

MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a

OBJS_DIR = objs/
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Werror -Wextra -g3 

NAME = so_long

all : $(MINI_LIBX) $(LIBFT) $(NAME)

#cree le dossier obj si il n existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#compile chaque .o dans le dossier obj
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MINI_LIBX):
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

re: fclean all

cleanbis:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C $(MINI_LIBX_DIR)

go: re cleanbis
	clear

.PHONY: all clean fclean re cleanbis go