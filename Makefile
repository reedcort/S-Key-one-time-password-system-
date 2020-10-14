CC=g++
CFLAGS=-Wall
DEPS = header.h
OBJ = client server

%: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)
S-key: $(OBJ)
	$(CC) -c -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) S-key
	rm -f *.txt