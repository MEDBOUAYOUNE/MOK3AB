NAME = cub3d

FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -rf
CC = clang
SRC = cub3d.c helps.c helps2.c get_next_line.c get_next_line_utils.c parce_map.c parce_map2.c main.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC)  $(OBJS)  $(FLAGS)  -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all