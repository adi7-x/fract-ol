CC = cc 

CFLAGS = -Wall -Wextra -Werror

GRAPHICS_LIBS = -lmlx -lXext -lX11

SRC = src/fract_ol.c src/fractal_init.c src/fractal_render.c src/math_utils.c \
	src/fract_ol_utils.c src/events.c src/fractal_calculations.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) $(HFILE)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(GRAPHICS_LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re