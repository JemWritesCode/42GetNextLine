NAME = GetNextLine
SRCS = ../../Get_Next_Line/*.c ./main.c
OBJS = ../../Get_Next_Line/*.o ./main.o
HDR = ../../Get_Next_Line/Get_Next_Line.h
FLAGS = -Wall -Wextra -Werror

LIBFT = ../../Get_Next_Line/libft/

all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. $(LIBFT)libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

# If you create a file named one of the rule names it still runs the make rule.
.PHONY: clean fclean all re