NAME = push_swap

COLOUR_GREEN=\033[92m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m

bold := $(shell tput bold)
sgr0 := $(shell tput sgr0)

SOURCES = $(shell ls libft_utils/*.c) $(shell ls mandatory/*.c) $(shell ls get_next_line/*.c) 

HEADER_FILES = get_next_line/get_next_line.h mandatory/push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

ECHO1 = @echo "$(COLOUR_GREEN)$(bold)Compiled all files successfully!$(sgr0)$(COLOUR_END)"
ECHO2 = @echo "$(COLOUR_YELLOW)$(bold)the executable $(NAME) created successfully!$(sgr0)$(COLOUR_END)"
ECHO3 = @echo "$(COLOUR_RED)$(bold)All Object files removed!$(sgr0)$(COLOUR_END)"
ECHO4 = @echo "$(COLOUR_RED)$(bold)the executable $(NAME) and removed!$(sgr0)$(COLOUR_END)"

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME) libftprintf puswapexc

$(NAME) : $(OBJECTS)
	$(ECHO1)
	ar rcs library $(OBJECTS)
    #ar rcs lib $? meaning add the newest changed objects

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

puswapexc : $(HEADER_FILES)
	$(CC) $(CFLAGS) mandatory/push_swap_main.c library libftprintf.a -o $(NAME)
	$(ECHO2)

libftprintf :
	@cd ft_printf && make && mv libftprintf.a ../

clean :
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(ECHO3)

fclean : clean
	$(RM) $(NAME) library libftprintf.a
	cd ft_printf && make fclean
	cd get_next_line && $(RM) *.o
	$(RM) *.dSYM .vscode
	$(ECHO4)

re : fclean all

.PHONY : clean fclean all re bonus