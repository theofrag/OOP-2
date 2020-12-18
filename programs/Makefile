# paths
INCLUDE =../include
MODULES=../modules

# compiler
CC = g++ 

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CPPFLAGS = -Wall  -g -I$(INCLUDE)
LDFLAGS = -lm

# Αρχεία .o
OBJS =  $(MODULES)/space.o main.o $(MODULES)/human.o 

# Το εκτελέσιμο πρόγραμμα
EXEC = main

ARGS= 1 1 2 4



$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)


clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: run
	valgrind ./$(EXEC)