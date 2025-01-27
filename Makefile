CSTD = -std=c11
WARN_FLAGS = -Wall -Wextra -pedantic
LDFLAGS = 
CFLAGS = $(CSTD) $(WARN_FLAGS) -g

SOURCE_DIR := src
OBJECT_DIR := src
OBJECTS := $(addprefix $(OBJECT_DIR)/, \
	argument_parser.o errors.o selection_methods.o chooser.o)
TARGET = chooser


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(TARGET) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

all: $(TARGET)  


.PHONY: all