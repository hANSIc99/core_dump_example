#gcc flags:
# -c assemble but do not link
# -g include debug information
# -o output
# -s make stripped libray

# uncomment the last part in line 10 to specify current working
# directory as the default search path for shared objects

CFLAGS =-Wall -Werror #-Wl,-rpath,$(shell pwd) 
#LIBS =# -L. -lmy_shared


all: main.o
	c++ -o coredump main.o $(CFLAGS)

main.o: main.cpp
	c++ -c main.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm *.o

