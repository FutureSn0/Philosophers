NAME = philo

CC = cc
CFLAGS = -Wextra -Wall -Werror -pthread
RM = rm -f

SRCS = philo.c \
	arg_check.c \
	cordination.c \
	data_init.c \
	dinner.c \
	set_and_return.c \
	status.c \
	thread_mutex_init.c \
	utills.c \
	cleanup.c \

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
