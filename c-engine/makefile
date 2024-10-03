CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

SRCS = main.c board.c valid.c data_structure/listc.c data_structure/stack.c

OBJS = $(SRCS:.c=.o)

TARGET = chess

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS) $(TARGET)