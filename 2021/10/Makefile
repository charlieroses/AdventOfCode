# Charlie Stuart : src322

.PHONY=clean

CC			= gcc
SOURCE		= general.c stack.c sort.c
HD_FILES	= fns.h dat.h
OBJ_FILES	= ${SOURCE:.c=.o}
C_FLAGS		= -lm

p1 : p1.c $(HD_FILES) $(OBJ_FILES)
	$(CC) p1.c $(OBJ_FILES) -o $@ $(C_FLAGS)

p2 : p2.c $(HD_FILES) $(OBJ_FILES)
	$(CC) p2.c $(OBJ_FILES) -o $@ $(C_FLAGS)

debugp1 : p1.c $(HD_FILES) $(OBJ_FILES)
	$(CC) -Wall -Wextra -g p1.c $(OBJ_FILES) -o $@ $(C_FLAGS)

debugp2 : p2.c $(HD_FILES) $(OBJ_FILES)
	$(CC) -Wall -Wextra -g p2.c $(OBJ_FILES) -o $@ $(C_FLAGS)

%.o : %.c
	$(CC) -g $(C_FLAGS) -c $<

clean :
	-rm $(MAIN)
	-rm *.o
