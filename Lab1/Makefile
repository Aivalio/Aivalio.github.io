# =========================
# Makefile for Gene & Protein project
# =========================

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable name
TARGET = lab1

# Object files
OBJS = main.o gene.o protein.o

# =========================
# Default target
# =========================
all: $(TARGET)

# =========================
# Build the final executable
# =========================
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# =========================
# Compile source files into object files
# =========================
main.o: main.cpp gene.h protein.h
	$(CXX) $(CXXFLAGS) -c main.cpp

gene.o: gene.cpp gene.h
	$(CXX) $(CXXFLAGS) -c gene.cpp

protein.o: protein.cpp protein.h
	$(CXX) $(CXXFLAGS) -c protein.cpp

# =========================
# Clean target — removes compiled files
# =========================
clean:
	rm -f $(OBJS) $(TARGET)

# =========================
# Run the program
# =========================
run: $(TARGET)
	./$(TARGET)
