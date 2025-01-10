NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror 
INC = -Iinc/
# -fsanitize=address

SRCS = $(shell find srcs -name "*.c")
OBJS = $(SRCS:srcs/%.c=objs/%.o)

ifeq ($(shell uname), Darwin)
	MLX = minilibx_opengl
	MLXFLAGS += -framework OpenGL -framework AppKit
	MLXLINK += -L$(MLX) -lmlx -framework OpenGL -framework AppKit
	INC += -I$(MLX)
else ifeq ($(shell uname), Linux)
	MLX = minilibx_linux
	MLXFLAGS += -lX11 -lXext -lm
	MLXLINK += -L$(MLX) -Lmlx -lmlx -lX11 -lXext -lm
	INC += -I$(MLX)
endif

MLXLIB = $(MLX)/libmlx.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIB) -o $(NAME) $(MLXFLAGS)

objs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -C libft/

$(MLXLIB):
	@make -C $(MLX) 2> /dev/null

norm:
	norminette srcs/ libft/ inc/

clean:
	rm -rf objs/
	make -C $(MLX) clean
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re norm
