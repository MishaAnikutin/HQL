# .PHONY: run

# test_ddl: test_ddl.c
# 	gcc -o output test_ddl.c ../DDL/create.c ../DDL/drop.c

# run: test_ddl
# 	./output

CC = gcc
CFLAGS = -Wall -Wextra -I../DDL 
LDFLAGS = -lm 
TARGETS = test_ddl test_tablespace 

../DDL/%.o: ../DDL/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGETS): %: %.c ../DDL/create.o ../DDL/drop.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test_tablespace: ../tablespace.o 
	$(CC) $(CFLAGS) $^ $< -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGETS) ../DDL/*.o ../tablespace.o
