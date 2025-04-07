NAME = libftprintf.a

SRCS = ft_printf.c ft_puthex_cnt.c ft_putlong_cnt.c ft_putstr_cnt.c ft_putuint_cnt.c \

FLAGS = -Wall -Wextra -g -Werror

CC = cc

CLEAN = rm -rf

OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rsc $(NAME) $(OBJ)

clean:
	@$(CLEAN) *.o

fclean: clean
	@$(CLEAN) *.a

re: fclean all

.PHONY: all clean fclean re bonus
