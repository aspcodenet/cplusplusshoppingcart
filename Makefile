PROG = main.exe 
SRC = main.cpp ShoppingCart.cpp
CFLAGS = -g -std=c++17
LIBS = -l gdi32 -l wsock32 -l ws2_32 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean