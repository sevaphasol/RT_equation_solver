@echo off
rm build/quad_solver.exe
rmdir build 
mkdir build
g++ src\main.c src\colors.c src\flags.c src\quad_solve.c src\quad_test.c src\user_interaction.c src\quad_assert.c -o build\quad_solver.exe -I include -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -fexceptions -pipe
