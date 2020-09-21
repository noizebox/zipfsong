CC=g++
CPPFLAGS=-std=c++17 -O3 -Wall

all: zipfsong zipfsong_cpp_fast

zipfsong: zipfsong.cpp
	$(CC) zipfsong.cpp $(CPPFLAGS) -o zipfsong

zipfsong_cpp_fast: zipfsong_cpp_fast.cpp
	$(CC) zipfsong_cpp_fast.cpp $(CPPFLAGS) -o zipfsong_cpp_fast

clean:
	rm ./zipfsong
	rm ./zipfsong_cpp_fast
