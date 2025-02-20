CC = gcc
CFLAGS = -Wall -Wextra -I./domain -I./repository -I./service

SRCS = main.c \
       domain/order.c \
       repository/order_repository.c \
       service/order_service.c

OBJS = $(SRCS:.c=.o)

EXEC = order_system.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)
