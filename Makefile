CC = g++
FLAGS = -I include -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -fexceptions -pipe

all: build\quad_solver

build\quad_solver: bin\main.o bin\colors.o bin\flags.o bin\quad_assert.o bin\quad_solve.o bin\quad_test.o bin\user_interaction.o
	$(CC) bin\main.o bin\colors.o bin\flags.o bin\quad_assert.o bin\quad_solve.o bin\quad_test.o bin\user_interaction.o -o build\quad_solver

bin\main.o: src\main.c
	$(CC) -c $(FLAGS) src\main.c -o bin\main.o

bin\colors.o: src\colors.c
	$(CC) -c $(FLAGS) src\colors.c -o bin\colors.o

bin\flags.o: src\flags.c
	$(CC) -c $(FLAGS) src\flags.c -o bin\flags.o

bin\quad_assert.o: src\quad_assert.c
	$(CC) -c $(FLAGS) src\quad_assert.c -o bin\quad_assert.o

bin\quad_solve.o: src\quad_solve.c
	$(CC) -c $(FLAGS) src\quad_solve.c -o bin\quad_solve.o

bin\quad_test.o: src\quad_test.c
	$(CC) -c $(FLAGS) src\quad_test.c -o bin\quad_test.o

bin\user_interaction.o: src\user_interaction.c
	$(CC) -c $(FLAGS) src\user_interaction.c -o bin\user_interaction.o

clean:
	rm -rf *.o hello
