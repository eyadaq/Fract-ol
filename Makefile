# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 05:04:44 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/01/07 23:09:41 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fractol
CC = cc
Flags = -Wall -Wextra -Werror
SRCS = main
srcDir = srcs/
incDir = includes/
objDir = obj/
libftDir = $(incDir)/libft
INCs = fractol.h
Srcs = $(addprefix $(srcDir), $(addsuffix .c, $(SRCS)))
OBJ = $(Srcs:$(srcDir)%.c=$(objDir)%.o)
INC = $(addprefix $(incDir), $(INCs))

all : $(Name)

$(Name) : $(OBJ) $(libftDir)/libft.a
	$(CC) $(Flags) -o $(Name) $(OBJ) -L$(libftDir) -lft -lmlx -lX11 -lXext -lm -lz

$(objDir)%.o: $(srcDir)%.c $(INC) | $(objDir)
	$(CC) $(Flags) -c $< -o $@

$(objDir):
	@mkdir -p $(objDir)

clean :
	@rm -rf $(objDir)
	$(MAKE) -C $(libftDir) clean

fclean : clean
	@rm -f $(Name)
	$(MAKE) -C $(libftDir) fclean

re : fclean all

$(libftDir)/libft.a:
	$(MAKE) -C $(libftDir)

.PHONY : all clean fclean re