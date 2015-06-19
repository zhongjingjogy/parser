CC = g++
CFLAGS = -g3 -Wall -pedantic -Wno-long-long -fmessage-length=0 -O3 -std=c++11

MAIN=test.cpp parser.cpp
EXE=test
INCLUDE=parser.h symcc.h

$(EXE):$(MAIN) $(INCLUDE)
	$(CC) $(CFLAGS) $(MAIN) -o $(EXE)

