CC := gcc
# CFLAGS := -Wall -Wextra -Werror

MAIN_FILES = philo.c ft_atoi.c philo_init.c await.c philos_manager.c join_threads.c \
routine.c timestamp.c setters.c getters.c monitoring.c safe_print.c clean_resources.c

MAIN_OBJS = $(MAIN_FILES:.c=.o)

NAME := philo

#ADS = -fsanitize=thread -g

all: $(NAME) clean

$(NAME): $(MAIN_OBJS)
	$(CC) $(MAIN_OBJS) -o $@ $(ADS)

%.o: %.c philo.h
	$(CC) -c $< -o $@

clean:
	rm -rf $(MAIN_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all