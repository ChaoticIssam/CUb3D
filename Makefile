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

all : 
	gcc -I /Users/deimos/Downloads/minilibx_macos -g -L /Users/deimos/Downloads/minilibx_macos -lmlx Libft/ft_atoi.c Libft/ft_bzero.c Libft/ft_calloc.c Libft/ft_isalnum.c Libft/ft_isalpha.c Libft/ft_isascii.c Libft/ft_isdigit.c Libft/ft_isprint.c Libft/ft_itoa.c Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_memcpy.c Libft/ft_memmove.c Libft/ft_memset.c Libft/ft_putchar_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_putstr_fd.c Libft/ft_split.c Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_striteri.c Libft/ft_strjoin.c Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strmapi.c Libft/ft_strncmp.c Libft/ft_strrchr.c Libft/ft_strtrim.c Libft/ft_substr.c Libft/ft_tolower.c Libft/ft_toupper.c ft_printf/call.c ft_printf/ft_printf.c create_map.c cub3d.c direction_paths.c error.c ft_strjoin1.c parssing.c parssing1.c parssing2.c parssing3.c player_images.c put_image.c read_map.c rgb.c wasd.c  -framework OpenGL -framework AppKit

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
	$(RM) a.out
	make fclean -C libft
	make fclean -C ft_printf
re:clean fclean all
	make re -C libft
	make re -C ft_printf
.PHONY: all clean fclean re