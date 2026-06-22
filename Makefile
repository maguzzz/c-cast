build:
	gcc -Wall -std=c99 src/*.c -o output.exe
run:
	./output
clean:
	del output.exe