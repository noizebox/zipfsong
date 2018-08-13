# Zipfsong
Solutions for the Spotify puzzle Zipf's Song that consists of reading a given list of songs and sorting and outputing a subset of them according to a given algorithm (Zipf's law). Full details of the puzzle used to be here [https://labs.spotify.com/puzzles/], but can now be found at [https://open.kattis.com/problems/zipfsong].
I wrote them as a personal challenge, use them for inspiration or reference but please don't submit them as your own work.

I have benchmarked my solutions against the other C++ and Python solutions I could find on Github and these are, afaik, the fastest and most efficient.

### zipfsong.cpp
This is a neat, by-the-book OOP solution using modern C++11 features. Reasonably efficient, but the string handling drags it down a bit as there are many small allocations to process.

### zipfsong_c_style.cpp
In an attempt to make the processing as efficient as possible, I tried a less elegant, more c-like solution. This copies the input data directly to memory in one big chunk before doing any processing. It then uses c-strings that point into this memory to represent the names. This way the title strings are never copied and together with cutting a few corners in the string to integer conversion makes for very efficient processing. Though not as elegant as the OOP solution above.

This solution manages to parse and sort 100000 songs in around 27 ms on an i7 laptop. In contrast, the oop solution above clocks in at around 56 ms at best, so about twice as fast.

### gen_testdata.cpp
I used this to generate 100000 random songs that I have used for benchmarking the solutions.
