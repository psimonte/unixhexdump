BIN += unixhexdump

all: $(BIN)

unixhexdump: unixhexdump.o
	gcc -o $@ $^

clean:
	rm -f *.o $(BIN)