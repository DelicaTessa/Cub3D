# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tclement <tclement@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/19 11:47:23 by tclement      #+#    #+#                  #
#    Updated: 2021/02/04 20:23:40 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = libft/libft.a

INCL_PATH = ./srcs/

HEADER = $(INCL_PATH)cub3d.h

CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.dylib

LFLAGS = -framework OpenGL -framework AppKit

SRC		= 	bitmap \
			error \
			cub3d \
			floodfill \
			handle_map \
			handle_sprites_one \
			handle_sprites_two \
			handle_window \
			init_structs \
			init_ray \
			keyhandling \
			main \
			move_player \
			parse_utils \
			parser_one \
			parser_two \
			raycasting \
			screencolor \
			utils

FILCUB3D = $(addsuffix .c, $(addprefix srcs/, $(SRC)))

OBJCUB3D = $(FILCUB3D:.c=.o)

all: $(NAME)

$(NAME): $(OBJCUB3D)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJCUB3D) -Lmlx -lmlx $(LFLAGS) $(LIBFT)

%.o: %.c $(HEADER) $(MLX)
	$(CC) -o $@ -c $< $(CFLAGS) -O3 -I. -I./mlx -I $(INCL_PATH)

$(MLX):
	@make -C libft
	@make -C ./mlx
	@cp ./mlx/$(MLX) $(MLX)

bonus: all

clean:
	rm -rf $(OBJCUB3D)
	rm -f screenshot.bmp
	make clean -C libft
	make clean -C mlx

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f libmlx.dylib

re: fclean all

.PHONY: all bonus clean fclean re
