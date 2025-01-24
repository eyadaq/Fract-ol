# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #

#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 23:21:58 by eaqrabaw          #+#    #+#              #
#    Updated: 2025/01/25 01:08:54 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = libft.a
CC = cc
AR = ar rcs
Flags = -Wall -Wextra -Werror
SRC = ft_atoi \
		ft_atod \
		ft_atol \
		ft_bzero \
		ft_calloc \
		ft_freedouble \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstsize \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_printf \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_puthexa \
		ft_putnbr_fd \
		ft_putptr \
		ft_putstr_fd \
		ft_putstr_printf \
		ft_putunsigned \
		ft_split \
		ft_strchr \
		ft_strcmp \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		get_next_line	
srcDir = src/
INCDIR = headers/
INCS = libft.h
objDir = obj/
SRCS = $(addprefix $(srcDir), $(addsuffix .c, $(SRC)))
OBJS = $(SRCS:$(srcDir)%.c=$(objDir)%.o)
INC = $(addprefix $(INCDIR), $(INCS))

all: $(Name)

$(Name): $(OBJS)
	@$(AR) $(Name) $(OBJS)

$(objDir)%.o: $(srcDir)%.c $(INC) | $(objDir)
	@$(CC) $(Flags) -c $< -o $@

$(objDir):
	@mkdir -p $(objDir)

clean:
	@rm -rf $(objDir)
	
fclean: clean
	@rm -f $(Name) 

re: fclean all

.PHONY: all clean fclean re
