#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/10/29 16:36:52 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FRAMEWORK = -framework OpenGl -framework Appkit
CPPFLAGS = -Iincludes/
CFLAGS = -Wall -Werror -Wextra
E1E2 = -lmlx

SRC_NAME = main.c draw.c mandelbrot.c julia.c burning.c fractal.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a
MLX = mlx_source/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft; $(MAKE) -f Makefile
#	@cd mlx_source; $(MAKE) -f Makefile
	gcc -o $(NAME) $(SRC) $(LIB) $(E1E2) $(CPPFLAGS) $(FRAMEWORK)
#	gcc -o $(NAME) $(SRC) $(LIB) $(MLX) $(CPPFLAGS) $(FRAMEWORK)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@cd libft; $(MAKE) -f Makefile clean
#	@cd mlx_source; $(MAKE) -f Makefile clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)
#	/bin/rm -f $(MLX)
	/bin/rm -f $(LIB)

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/