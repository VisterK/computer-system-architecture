task: main.c task_functions.o
	gcc -g -o task main.c task_functions.o -no-pie
task_functions.o: task_functions.asm
	nasm -f elf64 -g -F dwarf task_functions.asm -l task_functions.lst
