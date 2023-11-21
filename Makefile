# Compiler & flags declaration
CC=gcc
CFLAG=-Wall -g -o0

# Variable
CLEAN=clean

# Directory structure declaration
SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin
INIT=init
TESTDIR=tests
TESTBINDIR=$(TESTDIR)/$(BINDIR)

# Lib command
LIB_COMMAND=ar -rc
LIB=$(LIBDIR)/research.a

# Source configuration
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TESTS=$(wildcard $(TESTDIR)/*.c)
TESTBINS=$(patsubst $(TESTDIR)/%.c, $(TESTBINDIR)/%, $(TESTS))

all: $(LIB)

$(INIT):
	@mkdir -p -v $(OBJDIR) $(BINDIR) $(LIBDIR) $(TESTBINDIR)

$(LIB): $(CLEAN) $(INIT) $(OBJS)
	$(LIB_COMMAND) $(LIB) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAG) -c $< -o $@


.phony: run
.phony: clean

$(CLEAN):
	if [ -d "$(OBJDIR)" ]; then \
		rm -rfv $(OBJDIR); \
	fi \

	if [ -d "$(LIBDIR)" ]; then \
		rm -rfv $(LIBDIR); \
	fi \
	
	if [ -d "$(TESTBINDIR)" ]; then \
		rm -rfv $(TESTBINDIR); \
	fi \
	
	if [ -d "$(BINDIR)" ]; then \
		rm -rfv $(BINDIR); \
	fi \

$(TESTBINDIR)/%: $(TESTDIR)/%.c
	$(CC) $(CFLAG) $< $(OBJS) -o $@ -lcriterion -lm

test: $(CLEAN) $(LIB) $(TESTBINDIR) $(TESTBINS)
	for t in $(TESTBINS) ; do ./$$t --verbose ; done

$(TESTBINDIR):
	@mkdir $@

leak: clean $(LIB) $(TESTBINDIR) $(TESTBINS)
	for t in $(TESTBINS); do valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt  ./$$t; done

