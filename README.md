# zipfsong
Solutions for the Spotify puzzle zipfzong that consists of reading a given number of songs and sorting and outputing a subset of them according to a given algorithm (Zipf's law).
Use them for inspiration or reference but please don't send them in as your own.
### zipfsong.cpp
Neat C++11 style OOP solution.

### zipfsong_c_style.cpp
An attempt to make the processing as fast as I could (27 ms on my i7 laptop with 100000 songs). It uses a more c-like solution where the input data is copied to memory in bulk and the strings never copied.

### gen_testdata.cpp
Use this to generate a data file with 100000 random songs for benchmarking the solutions.
