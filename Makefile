SHELL	=	/bin/sh

INCLUDE	=	
LIBS	=	"-pthread"
CFLAGS	=	"-std=c++11"

play: threads.cpp
	$(CXX) $(CFLAGS) $(LIBS) $? $(LDFLAGS) -o $@ 

clean:
	rm *.out play

archive:
	tar -cvf matrix.tar *.cpp Makefile
	gzip matrix.tar
	mv matrix.tar.gz matrix.tgz