SRCS =
		

# mettre les differents noms de fichier de type ft_*\

NAME = so_long
#nom executable

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
#transfo en .o executable , code machine economie du temps de transfo .c -> .o
OBJECTS_PREFIXED = $(addprefix  $(OBJS_DIR), $(OBJS))

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -g3

MLX_FLAGS = -Lmlx -Imlx -lmlx -framework OpenGL -framework AppKit

#ajout des chemin de compilation pour trouver les .h
# -I indique ou chercher les entete
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a

$(LIBMLX) :
			@make -C ./minilibx-linux


$(LIBFT) : $(LIBFT_FILES)
			@make -C $(LIBFTPATH)

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling : $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(LIBFT) $(PRINTF)
	@$(CC) $(CC_FLAGS) $(OBJECTS_PREFIXED) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "Push_swap Done!"


$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(LIBMLX):
	@$(MAKE) -sC $(MLX_DIR)

all: $(NAME)


clean:
		rm -rf $(OBJS_DIR)

fclean : clean
		rm -f $(NAME)

re: fclean all