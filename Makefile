SOURCES = main.c mandelbrot.c colors.c zoom.c validate.c init_values.c julia.c
SOURCES+= errors.c key_map.c burning_ship.c

LIBFT = ./Libft/libft.a
MLX_LIB = ./mlx/libmlx.a

OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I . -I mlx -I Libft
NAME = fractol

CC = clang
AR = ar
RM = rm -f

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
ARFLAGS = rcs
MLX = -l Xext -l X11 -l m -l bsd

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			make all -C ./Libft
			make all -C ./mlx
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_LIB) $(MLX) -o $(NAME)

clean:
			$(RM) $(OBJECTS)
			make clean -C ./Libft
			make clean -C ./mlx

fclean:		clean
			$(RM) $(NAME)
			make -C ./Libft fclean

re: 		fclean all

