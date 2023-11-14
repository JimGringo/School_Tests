CC=gcc
CFLAGS=-c -Wall
SOURCES=hw6-main.c hw6-scan.c hw6-load.c hw6-search.c hw6-free.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hw6

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)