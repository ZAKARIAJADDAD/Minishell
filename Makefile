NAME=minishell
CC=cc #-fsanitize=address
#CFLAGS=-Wall -Wextra -Werror 

SRC=main.c BUILTINS/unset.c epur_str.c LIBFT/ft_strcmp.c get_env.c LIBFT/ft_split.c \
LIBFT/ft_substr.c LIBFT/ft_strlen.c LIBFT/ft_strdup.c LIBFT/ft_putstr_fd.c BUILTINS/echo.c\
BUILTINS/pwd.c LIBFT/ft_lstdelone.c BUILTINS/env.c BUILTINS/exit.c LIBFT/ft_bzero.c LIBFT/ft_calloc.c\
LIBFT/ft_atoi.c BUILTINS/CD.c BUILTINS/export.c LIBFT/ft_strchr.c LIBFT/ft_lstadd_back.c LIBFT/ft_lstnew.c\
LIBFT/ft_lstlast.c ft_split_t.c
OBJ= $(SRC:.c=.o)

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lreadline

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all