# Zipfsong
Solutions for the Spotify puzzle zipfzong that consists of reading a given number of songs and sorting and outputing a subset of them according to a given algorithm (Zipf's law). Full details of the puzzle here [https://labs.spotify.com/puzzles/]
I wrote them as a personal challenge, use them for inspiration or reference but please don't submit them as your own.

I have benchmarked my solutions against the other C++ and Python solutions I could find on Github (actually, there's only one other C++ solution and it is horribly slow, >1min ) and these are, afaik, the fastest and most efficient.

### zipfsong.cpp
This is a neat, by-the-book OOP solution using modern C++11 features. Reasonably efficient, but I think the string handling drags it down a bit. Many small allocations to process.

### zipfsong_c_style.cpp
In an attempt to make the processing as fast as I could, I tried a less elegant, more c-like solution. This copies the input data directly to memory in one big chunk before doing any processing. Then it uses c-strings that point into this memory to represent the names. Hence the title strings are never copied and this makes for very efficient handling. Though not as elegant as the above solution.

It can parse and sort 100000 songs in 27 ms on my i7 laptop. In contrast, the oop solution above clocks in at 68 ms, so more than twice as fast.

### gen_testdata.cpp
I used this to generate 100000 random songs that I have used for benchmarking the solutions.
