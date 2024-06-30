CC := gcc
# CFLAGS := -Wall -Wextra -Werror

MAIN_FILES = philo.c ft_atoi.c philo_init.c await.c create_philos.c join_threads.c \
lunch.c timestamp.c setters.c getters.c

MAIN_OBJS = $(MAIN_FILES:.c=.o)

NAME := philo

all: $(NAME)

$(NAME): $(MAIN_OBJS)
	$(CC) $(MAIN_OBJS) -o $@

%.o: %.c philo.h
	$(CC) -c $< -o $@

clean:
	rm -rf $(MAIN_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all