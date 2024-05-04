.PHONY: run

test_ddl: test_ddl.c
	gcc -o output test_ddl.c ../DDL/create_engine.c

run: test_ddl
	./output