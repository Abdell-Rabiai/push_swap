NAME = push_swap
BONUS_NAME = checker

COLOUR_GREEN=\033[92m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m

bold := $(shell tput bold)
sgr0 := $(shell tput sgr0)

SOURCES = $(shell ls libft_utils/*.c) $(shell ls mandatory/*.c | grep -v push_swap_main.c) $(shell ls get_next_line/*.c) 
BONUS_SOURCES = $(shell ls bonus/*.c)

HEADER_FILES = get_next_line/get_next_line.h mandatory/push_swap.h libft_utils/libft_utils.h bonus/checker_bonus.h

CC = cc

CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=address

RM = rm -rf

ECHO1 = @echo "$(COLOUR_GREEN)$(bold)Compiled all files successfully!$(sgr0)$(COLOUR_END)"
ECHO2 = @echo "$(COLOUR_YELLOW)$(bold)the executable $(NAME) created successfully!$(sgr0)$(COLOUR_END)"
ECHO3 = @echo "$(COLOUR_RED)$(bold)All Object files removed!$(sgr0)$(COLOUR_END)"
ECHO4 = @echo "$(COLOUR_RED)$(bold)the executable $(NAME) and removed!$(sgr0)$(COLOUR_END)"

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all : libftprintf $(NAME) 

# lib : $(OBJECTS) libftprintf
# 	$(ECHO1)
# 	ar rcs library $(OBJECTS)
    #ar rcs lib $? meaning add the newest changed objects

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :  $(OBJECTS) $(HEADER_FILES)
	 $(CC) $(CFLAGS) mandatory/push_swap_main.c $(OBJECTS) libftprintf.a -o $(NAME)

bonus : libftprintf $(BONUS_NAME)

$(BONUS_NAME) : $(OBJECTS) $(BONUS_OBJECTS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJECTS) $(BONUS_OBJECTS) libftprintf.a -o $(BONUS_NAME)

libftprintf :
	@cd ft_printf && make

clean :
	$(RM) $(OBJECTS) push_swap_main.o $(BONUS_OBJECTS)
	$(ECHO3)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME) library libftprintf.a
	cd ft_printf && make fclean
	cd get_next_line && $(RM) *.o
	$(RM) *.dSYM .vscode
	$(ECHO4)

re : fclean all

.PHONY : clean fclean all re bonus