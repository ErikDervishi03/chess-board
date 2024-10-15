CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# List of source files
SRC = main.c board.c valid.c data_structure/listc.c data_structure/stack.c # add your source files here

# Object files, generated from source files
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = chess_engine

# Default rule: compile and link
all: $(TARGET)

# Linking the object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the compiled object files and executable
clean:
	rm -f $(OBJ) $(TARGET)
