# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/10 16:19:10 by asulliva       #+#    #+#                 #
#    Updated: 2019/05/10 17:33:44 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = main.c draw.c helper.c read.c mlx.c extra.c colour.c
OBJ = main.o draw.o helper.o read.o mlx.o extra.o colour.o
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
GCC = gcc
LIBS = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/ > /dev/null
	@make -C minilibx_macos re > /dev/null
	@$(GCC) -g $(SRCS) -I /usr/X11/includes $(FLAGS) $(LIBS) > /dev/null
	@echo "\033[32mFDF READY\033[0m"

clean:
	@rm -rf $(OBJ) > /dev/null
	@make clean -C libft/ > /dev/null
	@make clean -C minilibx_macos/ > /dev/null
	@echo "\033[33mOBJ FILES REMOVED\033[0m"

fclean: clean
	@rm -rf $(NAME) > /dev/null 
	@make fclean -C libft/ > /dev/null
	@echo "\033[31mFDF REMOVED\033[0m"

re: fclean all
