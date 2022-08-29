# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:10:10 by ktashbae          #+#    #+#              #
#    Updated: 2022/04/13 19:20:05 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRC = ft_printf.c ft_parse_data.c ft_lstnew.c ft_convert.c \
ft_convert_string.c ft_convert_ptr_uxo.c ft_convert_num.c \

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
	ar rcs ${NAME} ${OBJ} ${LIBFTOBJ}
	

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@ 

bonus: fclean all

clean:
	${RM} ${OBJ} ${LIBFTOBJ}

fclean: clean
	${RM} ${OBJ} ${LIBFTOBJ}
	${RM} ${NAME}

re: fclean all
