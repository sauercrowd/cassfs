OBJS := $(patsubst %.c, obj/%.o, $(shell ls src/))
CFLAGS += -Wall -Iinclude/ $(shell pkg-config fuse3 --cflags)
LDFLAGS +=$(shell pkg-config fuse3 --libs)
TARGET = cassfs
#CC = gcc

all: cassfs

cassfs: obj $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

obj:
	mkdir obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGET) obj

.PHONY: clean
