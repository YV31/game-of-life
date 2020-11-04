CC=clang++
CFLAGS=-Wall -Wextra
LDFLAGS=-L/usr/local/lib -lraylib -lGLU -lm -ldl -lrt -lGLU -lX11 -lpthread -lxcb -lXau -lXdmcp
SRC=game-of-life.cpp

all: $(SRC)
	$(CC) $^ $(CFLAGS) $(LDFLAGS)
