# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jescully <jescully@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 09:50:54 by jescully          #+#    #+#              #
#    Updated: 2021/01/27 10:23:30 by jescully         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

SRC = libft/ft_atoi.c \
	libft/ft_memchr.c \
	libft/ft_putendl_fd.c \
	libft/ft_strdup.c \
	libft/ft_strncmp.c \
	libft/ft_toupper.c \
	libft/ft_bzero.c \
	libft/ft_memcmp.c \
	libft/ft_putnbr_fd.c \
	libft/ft_strjoin.c \
	libft/ft_strnstr.c \
	libft/ft_calloc.c \
	libft/ft_isdigit.c \
		libft/ft_memcpy.c \
		libft/ft_putstr_fd.c \
		libft/ft_strlcat.c \
		libft/ft_strrchr.c \
		libft/ft_isalnum.c \
		libft/ft_isprint.c \
		libft/ft_memmove.c \
		libft/ft_split.c \
		libft/ft_strlcpy.c \
		libft/ft_strtrim.c \
		libft/ft_isalpha.c \
		libft/ft_itoa.c \
		libft/ft_memset.c \
		libft/ft_strchr.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_isascii.c \
		libft/ft_memccpy.c \
		libft/ft_putchar_fd.c \
		libft/ft_strmapi.c \
		libft/ft_tolower.c \
		utils/ft_isflag.c \
		utils/ft_istype.c \
		utils/ft_appendchar.c \
		utils/ft_strnchr.c \
		ft_printf.c \
		utils/ft_putstr.c \
		utils/ft_chartostr.c \
		utils/ft_xtoa.c \
		utils/ft_lenflags.c \
		ft_printf.c \

BONSRC = 	libft/ft_lstsize.c \
      	libft/ft_lstadd_front.c \
 		libft/ft_lstnew.c \
     	libft/ft_lstlast.c \
      	libft/ft_lstadd_back.c \

OBJBON = $(BONSRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $? $(OBJ)
	ranlib $(NAME)

so: $(OBJ)
	$(CC) -shared -o libft.so $(OBJ)

clean:
	/bin/rm -f $(OBJ) $(OBJBON)

fclean: clean
	/bin/rm -f $(NAME)

bonus: $(OBJBON)
	ar rc $(NAME) $(OBJBON)
	ranlib $(NAME)

re: fclean all

