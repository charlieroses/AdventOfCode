# Charlie Stuart : src322
# CS-536 Fa21 : HW1

.PHONY=clean

CC			= gcc
MAIN_SRC	= $(MAIN).c
SOURCE		= math.c
HD_FILES	= fns.h
OBJ_FILES	= ${SOURCE:.c=.o}
C_FLAGS		=

p1 : p1.c $(HD_FILES) $(OBJ_FILES)
	$(CC) p1.c $(OBJ_FILES) -o $@ $(C_FLAGS)

p2 : p2.c $(HD_FILES) $(OBJ_FILES)
	$(CC) p2.c $(OBJ_FILES) -o $@ $(C_FLAGS)

debug : $(MAIN_SRC) $(HD_FILES) $(OBJ_FILES)
	$(CC) -Wall -Wextra -g $(MAIN_SRC) $(OBJ_FILES) -o $@ $(C_FLAGS)

%.o : %.c
	$(CC) -g $(C_FLAGS) -c $<

clean :
	-rm $(MAIN)
	-rm *.o
