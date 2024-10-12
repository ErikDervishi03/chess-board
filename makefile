CC = gcc
CFLAGS = -fPIC
LDFLAGS = -shared

OUTPUT = sharedC.so

SRCS = c-engine/main.c c-engine/board.c c-engine/valid.c c-engine/data_structure/listc.c c-engine/data_structure/stack.c
OBJS = $(SRCS:.c=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)
