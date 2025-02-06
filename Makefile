NAME = pipex

NAME_BONUS = pipex_bonus

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

SRC = pipex.c \
		src/parse.c 

SRC_BONUS = pipex_bonus.c \
			src_bonus/heredoc.c \
			src_bonus/parse_bonus.c

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(SRC_BONUS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo -n "Loading"
	@for i in {1..5}; do \
		echo -n "."; \
		sleep 0.5; \
	done
	@echo "✅"
	@echo "Files were generated successfully!✅✅✅"

bonus: $(LIBFT_A) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ)
	@$(CC) $(CC_FLAGS) $(BONUS_OBJ) $(LIBFT_A) -o $(NAME_BONUS)
	@echo -n "Loading"
	@for i in {1..5}; do \
		echo -n "."; \
		sleep 0.5; \
	done
	@echo "✅"
	@echo "Files were generated successfully!✅✅✅"

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT) -s 

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C $(LIBFT) -s
	@echo -n "Cleaning"
	@for i in {1..5}; do \
		echo -n "."; \
		sleep 0.5; \
	done
	@echo "✅"
	@echo "Files were deleted correctly!✅✅✅"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT) -s

re: fclean all

t:
	@clear
	@echo "=== My pipex --------------TEST------------ ===\n"
	@echo "input_file:\n------------------------------------------"
	@cat input_file
	@echo "\n------------------------------------------"
	@echo "Executando: ./$(NAME) input_file $(CMD1) $(CMD2) output_file"
	@valgrind ./$(NAME) input_file "$(CMD1)" "$(CMD2)" output_file
	@echo "\nSaída do output_file:"
	@cat output_file
	@echo "\nNúmero de linhas: $(shell cat output_file | wc -l)"

	@echo "\n=== Original pipe --------------TEST------------ ===\n"
	@echo "input_file_bash:\n------------------------------------------"
	@cat input_file_bash
	@echo "\n------------------------------------------"
	@echo "Executando: cat input_file_bash | $(CMD1) | $(CMD2) output_file_bash"
	@cat input_file_bash | $(CMD1) | $(CMD2) > output_file_bash
	@echo "\nSaída do output_file_bash:"
	@cat output_file_bash
	@echo "\nNúmero de linhas: $(shell cat output_file_bash | wc -l)"

empty:
	@echo "Emptying files: output_file, output_file_bash"
	@: > output_file
	@: > output_file_bash

c:
	@find . -type f -iname "*.c" -exec grep "//" {} +

.PHONY: all clean fclean re v c bonus t
