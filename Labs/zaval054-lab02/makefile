CXX=g++
CXXFLAGS = -std=c++11 -g

all: book_app

book_app: main.o book.o
	$(CXX) $(CXXFLAGS) main.o book.o -o book_app

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

book.o: book.cc book.h
	$(CXX) $(CXXFLAGS) -c book.cc -o book.o

clean:
	rm -f *.o book_app