CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET= overcurrent_calculator
SOURCES=main.c	overcurrent_calculator.c
OBJECTS=$(SOURCES:.c=.o)


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(TARGET)