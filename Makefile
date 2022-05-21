NAME = fdf

CFLAGS = -Wall -Werror -Wextra
LINK_MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
FS = -fsanitize=address
CC = cc

FUNCTIONS = manage_error.c ft_puts.c gnl.c utils.c read_map.c print_map.c ft_split.c fdf.c \
			check_map.c ft_atoi.c fdf_utils.c  draw_grid.c get_cords.c print_tri.c\
			map_dim.c cords_atoi.c plot_line.c free_utils.c check_get_map.c display.c\
			drawing.c

OBJECTS =  $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LINK_MLX) $(OBJECTS) -o $(NAME)
	@echo "FDF CREATED"

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)
	@echo "FDF REMOVED"

re : fclean all