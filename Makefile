NAME = Fillit

SRCS=

INCL = -I ./

SRCO = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $(INCL) $^

clean:
	rm -f $(SRCO)

flcean: clean
	rm -f $(NAME)

re: fclean all
