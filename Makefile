NAME = philo
CC = clang
FLAGS = -Wall -Werror -Wextra
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = -Iinclude 
RM = rm -rf

SRC = $(MYFT) $(FILES)

MYFT = ft_atoi.c ft_atoll.c ft_bzero.c ft_get_time.c ft_usleep.c
FILES = parsing.c forks.c routine.c ft_log.c knock.c exit.c

MYFT := $(MYFT:%.c=myft/%.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE:%.h=$(INC_DIR)/%.h)
	@$(CC) $(INC_DIR) $(FLAGS) -o $(NAME) src/philosophers.c $(OBJ) -lpthread

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(INC_DIR) $(FLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re