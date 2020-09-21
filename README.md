# Zipfsong
Solutions for the Spotify puzzle Zipf's Song that consists of reading a given list of songs, sorting them according to a given algorithm (Zipf's law), and outputting the top n songs. Full details of the puzzle used to be here [https://labs.spotify.com/puzzles/], but can now be found at [https://open.kattis.com/problems/zipfsong].
I wrote them as a personal challenge, use them for inspiration or reference but please don't submit them as your own work.

I have benchmarked my solutions against the other C++ and Python solutions I could find on Github and these are, afaik, the fastest and most efficient. The C-style variant below is also the fastest solution submitted to [Kattis](https://open.kattis.com/problems/zipfsong/statistics).

### zipfsong.cpp
This is a neat, by-the-book OOP solution using modern C++ features. Reasonably efficient, but the string handling drags it down a bit as there are many small heap allocations to process and string data is copied several times.

### zipfsong_cpp_fast.cpp
A no holds barred kind of attempt at making the processing as efficient as possible, Originally written in a more old school C-style fashion which used char pointers to store the title strings, but eventually rewritten to use std::string_view instead. This solution copies the input data directly to memory in one big chunk before doing any processing. The title strings then point into this memory directly and the string data is never copied. 

It also cuts a few corners in the string to integer conversion which makes for very efficient processing. Though not as elegant as the OOP solution above. This solution manages to parse and sort 100000 songs in around 27 ms on an i7 laptop. In contrast, the oop solution above clocks in at around 56 ms at best, so about twice as fast.

### gen_testdata.cpp
Used to generate 100000 random songs that I have used for benchmarking the solutions.
