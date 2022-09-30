NAME = fdf

CFLAGS = -Wall -Werror -Wextra
LINK_MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
FS = -fsanitize=address
CC = cc

FUNCTIONS = drawing/def_unit.c \
			drawing/display.c \
			drawing/drawing.c \
			drawing/find_ext_z.c \
			drawing/my_mlx_pixel_put.c \
			drawing/plot_line.c \
			parsing/check_get_map.c \
			parsing/cords_atoi.c \
			parsing/get_cords.c \
			parsing/map_dim.c \
			parsing/read_map.c \
			utils/free_utils.c \
			utils/ft_atoi.c \
			utils/ft_puts.c \
			utils/ft_split.c \
			utils/gnl.c \
			utils/handle_closing.c \
			utils/hex_to_int.c \
			utils/print_map.c \
			utils/print_tri.c \
			utils/s_atoi.c \
			utils/to_isom.c \
			utils/utils.c\
			fdf.c

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