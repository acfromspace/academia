# HOW TO USE
# In your terminal, change directory to a1 (if you do not have one, make one w/ mkdir a1).
# Check to see if you have a1.c, a1.h within the folder before you proceed.
#
# TERMINAL COMMANDS
# make -> creates the executable (player.exe)
# filem -> runs the executable
# make clean -> removes all files created from make
# rm FILE_NAME -> removes a specific file
# rm -r DIRECTORY_NAME -> removes a specific directory

EXEC = filem
BEFOREFILES = main.c a2.c a2.h
CC = gcc
LFLAGS = -pthread
CFLAGS = -c

OBJECTS = $(BEFOREFILES:.c=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.txt *.bak *.o $(EXEC)