CC=g++
CPPFLAGS=-std=c++17 -O3 -Wall

zipfsong:
	$(CC) zipfsong.cpp $(CPPFLAGS) -o zipfsong

zipfsong_c_style:
	$(CC) zipfsong_c_style.cpp $(CPPFLAGS)-o zipfsong_c_style