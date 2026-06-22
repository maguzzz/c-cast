build:
	gcc -Wall -std=c99 src/*.c -lmingw32 -lSDL2main -lSDL2 -o output.exe
run:
	./output
clean:
	del output.exe