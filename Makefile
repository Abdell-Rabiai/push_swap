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

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

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

$(NAME) :  $(OBJECTS) mandatory/push_swap_main.o $(HEADER_FILES)
	 $(CC) $(CFLAGS) mandatory/push_swap_main.c $(OBJECTS) libftprintf.a -o $(NAME)

bonus : libftprintf $(BONUS_NAME)

$(BONUS_NAME) : $(OBJECTS) $(BONUS_OBJECTS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJECTS) $(BONUS_OBJECTS) libftprintf.a -o $(BONUS_NAME)

libftprintf :
	@cd ft_printf && make

clean :
	$(RM) $(OBJECTS) mandatory/push_swap_main.o $(BONUS_OBJECTS)
	$(ECHO3)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME) library libftprintf.a
	cd ft_printf && make fclean
	cd get_next_line && $(RM) *.o
	$(RM) *.dSYM .vscode
	$(ECHO4)

re : fclean all

.PHONY : clean fclean all re bonus


# int sort_3(t_deque *deq)
# {
#     t_node *curr;

#     // Set the current node to the second node in the deque
#     curr = deq->first->next;
#     // If the first value is greater than the second value {3, 2, 1}
#     if (deq->first->num > curr->num)
#     {
#         // Move to the third node
#         curr = curr->next;
#         // If the first value is greater than the third value {3, 2, 1}
#         if (deq->first->num > curr->num)
#             // Move the first value to the end of the deque {2, 1, 3}
#             do_ra(deq);
#         // Set the current node to the second node in the deque
#         curr = deq->first->next;
#         // If the first value is greater than the second value {2, 1, 3}
#         if (deq->first->num > curr->num)
#             // Swap the positions of the first and second values {1, 2, 3}
#             do_sa(deq);
#     }
#     // If the first value is less than the second value {1, 3, 2}
#     else
#     {
#         // If the second value is less than the third value (already sorted in current state)
#         if (curr->num < curr->next->num)
#             // Swap the positions of the first and second values
#             do_sa(deq);
#         // If the second value is greater than the third value {1, 3, 2}
#         else if (curr->num > curr->next->num)
#         {
#             // Move the last value to the front of the deque {2, 1, 3}
#             do_rra(deq);
#             // If the first value is greater than the second value
#             if (deq->first->num > deq->first->next->num)
#                 // Swap the positions of the first and second values {1, 2, 3}
#                 do_sa(deq);
#         }
#     }
#     // Return 0 to indicate successful completion of the function
#     return (0);
# }

# 3 		 2		 1
# 2   ra	 1   sa  2
# 1		 3		 3

# 3 		 1		 
# 1   ra   2
# 2		 3

# 2		1
# 1   sa  2
# 3 		3
# /******** else ********/

# 1 // this one is sorted, nothing to do
# 2
# 3

# 1 		 2		  1
# 3   rra  1   sa   2
# 2		 3 		  3

# 2		 1
# 3   rra  2 
# 1  		 3 