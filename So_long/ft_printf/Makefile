CC = clang
CFLAGS = -Wall -Werror -Wextra -fPIC
AR = ar
ARFLAGS = crs

SRCS = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunsigned.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) -o $(NAME) $(OBJS)
$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRCS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
