NAME = GetNextLine
SRCS = ../../Get_Next_Line/get_next_line.c ./main.c
OBJS = ../../Get_Next_Line/*.o ./main.o
HDR = ../../Get_Next_Line/Get_Next_Line.h
FLAGS = -Wall -Wextra -Werror

LIBFT = ../../Get_Next_Line/libft/
LIBFTHDR = ../../Get_Next_Line/libft/libft.h

all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(LIBFTHDR) -L. $(LIBFT)libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

debug: re 
	make -C $(LIBFT)
	gcc $(FLAGS) -o debugGNL $(SRCS) -I $(LIBFTHDR) -L. $(LIBFT)libft.a -g

# With PHONY if you create a file named one of the rule names it still runs the make rule.
.PHONY: clean fclean all re