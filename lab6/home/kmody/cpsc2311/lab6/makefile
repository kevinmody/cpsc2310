# Config, just variables
CC=gcc
CFLAGS=-Wall -g 
LFLAGS=-lm 
TARGET=lab6 
 
# Generate source and object lists, also just string variables
C_SRCS := \
  $(wildcard *.c) \
  $(wildcard src/*.c) \
  $(wildcard src/**/*.c) 

HDRS := \
  $(wildcard *.h) \
  $(wildcard src/*.h) \
  $(wildcard src/**/*.h) 

which: 
		@echo "FOUND SOURCES: ${C_SRCS}" 
		@echo "FOUND HEADERS: ${HDRS}" 
# default target
all: build
		@echo “All Done!”
 
# Link all built objects 
build: $(OBJS) 
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# special build rule
%.o: %.c $(HDRS) 
		$(CC) $(CFLAGS) -c $< -o $@ 
