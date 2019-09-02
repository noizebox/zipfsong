CC=g++
CPPFLAGS=-std=c++17 -O3 -Wall

all: zipfsong zipfsong_c_style

zipfsong: zipfsong.cpp
	$(CC) zipfsong.cpp $(CPPFLAGS) -o zipfsong

zipfsong_c_style: zipfsong_c_style.cpp
	$(CC) zipfsong_c_style.cpp $(CPPFLAGS) -o zipfsong_c_style

clean:
	rm ./zipfsong
	rm ./zipfsong_c_style