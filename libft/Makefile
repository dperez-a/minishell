# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 11:19:51 by fsantill          #+#    #+#              #
#    Updated: 2023/10/12 16:48:25 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

OBJ=$(FT:%.c=%.o)

BONUS=	ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstadd_back_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

OBJBONUS= $(BONUS:%.c=%.o)
bonuses = .cache

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus:$(bonuses)

$(bonuses): $(NAME) $(OBJBONUS)
	ar -rcs $^
	ar -rcs $(bonuses) $^

t: $(NAME) testeos.o
	cc testeos.o -o testeos -L. -lft

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) $(OBJBONUS)
fclean: clean
	rm -rf $(NAME) $(bonuses)
re: fclean $(NAME)

# flag -g3 allow debugger (not included).
# flags -Wall, -Werror y -Wextra. Need a Makefile without relink.
# Makefile containing norms $(NAME), all, clean, fclean y re.

# %.o:%.c
#	$(CC) $(CFLAGS) -c $<