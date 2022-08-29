# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:10:10 by ktashbae          #+#    #+#              #
#    Updated: 2022/08/29 17:49:46 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRC = src/ft_printf.c src/ft_parse_data.c src/ft_lstnew.c src/ft_convert.c \
src/ft_convert_string.c src/ft_convert_ptr_uxo.c src/ft_convert_num.c \

LIBFTSRC = libft/ft_isdigit.c libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c \
libft/ft_itoa_base.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strjoin.c \
libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strrchr.c 

OBJ = ${SRC:.c=.o}
LIBFTOBJ = ${LIBFTSRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME} 

${NAME}: ${OBJ} ${LIBFTOBJ} ft_printf.h
	@ar rcs ${NAME} ${OBJ} ${LIBFTOBJ}
	@echo "\033[0;32m [ft_printf is compiled.]"
	

%.o: %.c ft_printf.h
	@${CC} ${CFLAGS} -c $< -o $@ 

bonus: fclean all

clean:
	@${RM} ${OBJ} ${LIBFTOBJ}

fclean: clean
	@${RM} ${OBJ} ${LIBFTOBJ}
	@${RM} ${NAME}

re: fclean all
