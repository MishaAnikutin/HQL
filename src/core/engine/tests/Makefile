.PHONY: run

test_ddl: test_ddl.c
	gcc -o output test_ddl.c ../DDL/create.c ../DDL/drop.c

run: test_ddl
	./output