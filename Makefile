RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
PURPLE	=	\033[94;1m
CLEAR	=	\033[0m

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-I/opt/homebrew/opt/readline/inc # Flag para readline en macOS
LDFLAGS = -L/opt/homebrew/opt/readline/lib #-lreadline # Flag para readline en macOS

# Rutas de fuentes y objetos
SRC_DIR = ./src
OBJ_DIR = ./obj

# Archivos fuente y objeto
SRC = 	$(SRC_DIR)/lexer/tokenizer.c \
		$(SRC_DIR)/lexer/token_utils.c \
		$(SRC_DIR)/lexer/token_lst_utils.c \
		$(SRC_DIR)/lexer/token_lst_utils_2.c \
		$(SRC_DIR)/main/main.c \
		$(SRC_DIR)/debug/debug.c \
		$(SRC_DIR)/utils/error.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Ruta de la biblioteca libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(OBJ_DIR) $(NAME)

# Crear directorios para objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/lexer
	@mkdir -p $(OBJ_DIR)/main
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/debug
	@echo "$(YELLOW)Creando directorios de objetos en $(OBJ_DIR)...$(CLEAR)"

# Regla principal para compilar el programa
$(NAME): $(OBJ) $(LIBFT)
	@echo "$(PURPLE)Compilando $(NAME)...$(CLEAR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBFT)
	@echo "$(GREEN)$(NAME) compilado correctamente.$(CLEAR)"

# Regla para compilar libft
$(LIBFT):
	@echo "$(PURPLE)Compilando libft...$(CLEAR)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)libft compilada correctamente.$(CLEAR)"

# Regla para compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compilando $<...$(CLEAR)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)Archivos objeto eliminados.$(CLEAR)"

# Limpieza completa
fclean: clean
	@rm -f $(NAME) $(OBJ_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)$(NAME) eliminado completamente.$(CLEAR)"

# Reconstrucción completa
re: fclean all

run: all
	@clear
	@./$(NAME)

# Descomentar para depuración con valgrind
VALGRIND_FLAGS=#--leak-check=full
valgrind: all
	@clear
	@valgrind $(VALGRIND_FLAGS) ./$(NAME)

.PHONY: all clean fclean re
