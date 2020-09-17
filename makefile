# Source, Executable, Includes, Library Defines
INCL   = $(wildcard *.h)
SRC    = $(wildcard *.c)
OBJ    = $(SRC:.c=.o)
LIBS   = -lm
EXE    = alcobra

TEST_DIR = ./tests
TEST_INC_DIR =
TEST_LIBS = -lm
TEST_EXE = ./tests/test

# Compiler, Linker Defines
CC      = /usr/bin/gcc
CFLAGS  = -std=c99 -Wall -O2
LIBPATH = -L.
LDFLAGS = -o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG = -std=c99c -Wall -g -DDEBUG $(LDFLAGS)
RM      = /bin/rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -c $(CFLAGS) $*.c

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

# Objects depend on these Libraries
$(OBJ): $(INCL)

test: matrix.o $(TEST_DIR)/tests.c
	$(CC) $(CFLAGS) -o $(TEST_DIR)/$@ $^ $(TEST_INC_DIR) $(TEST_LIBS)
	@$(TEST_EXE) || true

# Create a gdb/dbx Capable Executable with DEBUG flags turned on
debug:
	$(CC) $(CFDEBUG) $(SRC)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) core a.out
	rm -f $(TEST_DIR)/*_test

run:
	@./$(EXE) || true
