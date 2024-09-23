SRCS = get_next_line.c get_next_line_utils.c \
	map_checker.c map_init.c \
	so_long.c \

NAME = so_long

OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -I./libft -I./mlx
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "so_long compiled!"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re