CC=clang++
CFLAGS=-Wall -Wextra
LDFLAGS=-L/usr/local/lib -lraylib -lGLU -lrt -lm -ldl -lrt -lm -ldl -lrt -lm -ldl -lGLU -lrt -lm -ldl -lrt -lm -ldl -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp
SRC=game-of-life.cpp

all: $(SRC)
	$(CC) $^ $(CFLAGS) $(LDFLAGS)
