CC = gcc
CFLAGS = -Wall -g
TARGET = priority_queue
TEST_TARGET = test_priority_queue

# Ορίζουμε τα αρχεία πηγαίου κώδικα
SRCS = main.c PQImplementation.c
TEST_SRCS = test_priority_queue.c PQImplementation.c
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Η εντολή για το πρόγραμμα
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Η εντολή για τα unit tests
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Κανόνες για να μεταγλωττίσουμε τα αρχεία .c σε .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Εντολή για καθαρισμό των .o και εκτελέσιμων αρχείων
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)
