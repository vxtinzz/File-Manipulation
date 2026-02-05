CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/create.c src/read.c src/update.c src/delete.c
OUT = build/crud.exe

all: build $(OUT)

build:
	mkdir -p build

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

<<<<<<< HEAD
clean:
	rm -rf build

run: all
	./build/crud.exe

=======
ifeq ($(OS),Windows_NT)
clean:
	del /Q $(BIN).exe 2>nul || true
else
clean:
	rm -f $(BIN)
endif
>>>>>>> 7e86d7708ad4c3fbd671e086685d405de159171c
