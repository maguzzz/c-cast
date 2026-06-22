CC = gcc
CFLAGS = -Wall -std=c99

rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC = $(call rwildcard,src/,*.c)

OUT = build/output.exe

.PHONY: all build run clean

all: build run

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f build/*.exe