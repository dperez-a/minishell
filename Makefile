RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
PURPLE	=	\033[94;1m
CLEAR	=	\033[0m

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I/opt/homebrew/opt/readline/inc #the last flag is for compiling readline on mac
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline #ldflag for mac
SRC = 	./src/main/main.c \
		./src/parse/process.c ./src/parse/tokenize_input.c ./src/parse/tokenize_utils.c \
		./src/redirect/redir_types.c ./src/redirect/redir_utils.c ./src/redirect/redir.c

OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(PURPLE)Compiling minishell...$(CLEAR)"
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) -lreadline -ltermcap $(LIBFT)
	@echo "$(GREEN)minishell compiled!$(CLEAR)"

$(LIBFT):
	@echo "$(PURPLE)Compiling libft...$(CLEAR)"
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compiled!$(CLEAR)"

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)minishell objects removed!$(CLEAR)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)minishell removed!$(CLEAR)"
	@rm -rf Historial

re: fclean $(NAME)

run: all
	@clear
	@./$(NAME)


# Descomment the line to get leaks
VALGRIND_FLAGS=#--leak-check=full
valgrind: all
	@clear
	@valgrind $(VALGRIND_FLAGS) ./$(NAME)

.PHONY: all clean fclean re