.PHONY: build run clean

build:
	mkdir build
	gcc -Wall src/main.c src/network/network.c -o build/out

run:
	./build/out

clean:
	rmdir /s /q build