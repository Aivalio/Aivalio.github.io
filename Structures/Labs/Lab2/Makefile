# Compiler settings
CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lm
PROGRAM = main
LAB = test

OBJS = main.o list.o
LAB_OBJS = test_module.o list.o

# Compile the main program
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

# Compile the test program
$(LAB): $(LAB_OBJS)
	$(CC) $(CFLAGS) $(LAB_OBJS) $(LDFLAGS) -o $(LAB)

# Clean up generated files
clean:
	rm -f $(PROGRAM) $(OBJS) $(LAB) $(LAB_OBJS)

# Run unit tests
test: $(LAB)
	./$(LAB)

# Compile with tests
test_program: $(OBJS) test_module.o
	$(CC) $(CFLAGS) $(OBJS) test_module.o $(LDFLAGS) -o $(PROGRAM)
