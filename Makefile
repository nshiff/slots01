CFLAGS= -g -Wall -pedantic -std=c11
SOURCE_FILES=main.c slots.h

run: $(SOURCE_FILES)
	gcc -o slots $(SOURCE_FILES) $(CFLAGS)
	./slots
