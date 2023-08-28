NAME = cub3d

FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -rf
CC = clang
SRC = parse/cub3d.c gnl/helps.c parse/helps2.c gnl/get_next_line.c gnl/get_next_line_utils.c \
	 parse/parce_map.c parse/parce_map2.c main.c render_2d.c mlx_hooks.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) -fsanitize=address -g3 $(OBJS)  $(FLAGS)  -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all