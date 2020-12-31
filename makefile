
# These are variables. We usually define CC, CCLINK, CFLAGS, OBJS, EXEC and RM
CC=gcc
CCLINK=$(CC) # Read variable CC using $(CC)
CFLAGS=-g -Wall -std=c99
OBJS=ransom.o
EXEC=prog.exe
RM=clean

# The first rule is invoked by default.
# We can also invoke it (or any other rule) manually with "make all" - 
# note that "all" is the rule's name!
$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC)

# Full rule syntax with custom Shell commands according to linked list
ransom.o: ransom.c
	$(CC) $(CFLAGS) -c ransom.c


# We usually have a "clean" rule to delete any automatically generated files
$(RM):
	rm -rf *.o *.exe