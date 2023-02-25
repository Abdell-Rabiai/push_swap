# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:20:54 by arabiai           #+#    #+#              #
#    Updated: 2023/02/25 13:38:30 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

COLOUR_GREEN=\033[92m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m

bold := $(shell tput bold)
sgr0 := $(shell tput sgr0)

SOURCES = ft_printf.c ft_printf_utils.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

ECHO1 = @echo "$(COLOUR_GREEN)$(bold)Compiled all files successfully!$(sgr0)$(COLOUR_END)"
ECHO2 = @echo "$(COLOUR_YELLOW)$(bold)the library $(NAME) created successfully!$(sgr0)$(COLOUR_END)"
ECHO3 = @echo "$(COLOUR_RED)$(bold)Object files removed!$(sgr0)$(COLOUR_END)"
ECHO4 = @echo "$(COLOUR_RED)$(bold)the library $(NAME) removed!$(sgr0)$(COLOUR_END)"

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) ft_printf.h
	$(ECHO1)
	ar rc $(NAME) $?
	$(ECHO2)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)
	$(ECHO3)

fclean : clean
	$(RM) $(NAME)
	$(ECHO4)

re : fclean all

.PHONY : clean fclean all re
