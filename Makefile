SHELL	=	/bin/sh

INCLUDE	=	
LIBS	=	-pthread -lncurses
CFLAGS	=	-std=c++11

play: threads.cpp window.cpp shuffle.cpp window.h
	$(CXX) $(CFLAGS) $? $(LDFLAGS) -o $@ $(LIBS)

clean:
	rm *.out play

archive:
	tar -cvf matrix.tar *.cpp Makefile
	gzip matrix.tar
	mv matrix.tar.gz matrix.tgz