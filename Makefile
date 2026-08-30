CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/queue.c src/scheduler.c src/threads.c
OBJ = $(SRC:.c=.o)

libthreads.a: $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o libthreads.a
