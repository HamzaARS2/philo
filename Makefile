CC := gcc
CFLAGS = -Wall -Wextra -Werror

MAIN_FILES = philo.c ft_atoi.c philo_init.c await.c philos_manager.c join_threads.c \
routine.c timestamp.c setters.c getters.c monitoring.c safe_print.c clean_resources.c

MAIN_OBJS = $(MAIN_FILES:.c=.o)

NAME := philo


all: $(NAME)

$(NAME): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $@

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(MAIN_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all