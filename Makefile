NAME = CUB3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = cub3d.c\
			create_map.c\
			error.c\
			ft_strjoin1.c\
			direction_paths.c\
			parssing.c\
			parssing1.c\
			parssing2.c\
			parssing3.c\
			player_images.c\
			put_image.c\
			read_map.c\
			rgb.c\
			wasd.c\

LIBFT_OB = libft/libft.a
FT_PRINTF_OB = ft_printf/libftprintf.a

OBJECTS = ${SOURCES:.c=.o}

all : $(NAME) $(LIBFT_OB)

$(NAME):	$(OBJECTS) $(LIBFT_OB)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJECTS) $(LIBFT_OB) $(FT_PRINTF_OB) -o $(NAME)

$(LIBFT_OB):
	make all -C libft
	make -C ./ft_printf

clean:
	$(RM)	$(OBJECTS)
	make clean -C libft
	make clean -C ft_printf
fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
re:clean fclean all
	make re -C libft
	make re -C ft_printf
.PHONY: all clean fclean re