# =========================
#         Makefile
# =========================

# Compiler & Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Executable name
EXEC = main

# Source files
SRC = main.cpp sequence.cpp dna.cpp rna.cpp protein.cpp isoform.cpp gene.cpp

# Object files (auto conversion: .cpp -> .o)
OBJ = $(SRC:.cpp=.o)

# =========================
#      Build Target
# =========================
all: $(EXEC)

# Link all object files into executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# =========================
#     Compilation Rule
# =========================
# ΠΩΣ από κάποιο .cpp φτιάχνουμε .o (και αναζητά .h εξαρτήσεις)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
#     Clean Commands
# =========================

# ΔΙΑΓΡΑΦΕΙ τα .o μόνο
clean:
	rm -f *.o

# ΔΙΑΓΡΑΦΕΙ executable + .o
distclean: clean
	rm -f $(EXEC)

# =========================
#   Quality of life alias
# =========================
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean distclean run
