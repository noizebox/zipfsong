//*******************************************
// Spotify puzzle #2 - Zipf's song
// Gustav Andersson - 200921
// gustav.k.andersson@gmail.com
//
// Solved by dumping the input from memory quickly and without processing. Don't copy
// any string data, but use string_views that point into this memory (an improvement
// over old c-style string)
//*******************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <string_view>

// Save a few cycles by replacing atoi() with a version that assumes positive integers and no characters in string
inline uint64_t unsafe_strtol(const std::string_view& s)
{
    uint64_t res{0};
    for (auto c : s)
    {
        res = (res * 10) + (c - '0');
    }
    return res;
}

class Song
{
public:
    Song(std::string_view name, int64_t rating) : _name(name), _rating(rating) {}

    const std::string_view& name() const { return _name; };
    friend bool operator< (const Song& lhs, const Song& rhs){ return lhs._rating < rhs._rating; };
    friend bool operator> (const Song& lhs, const Song& rhs){ return rhs < lhs; };

private:
    std::string_view   _name;
    int64_t            _rating;
};

void parse_songs(const int songs, std::vector<Song>& song_list, char* mem, size_t mem_size)
{
    song_list.reserve(songs);
    std::cin.read(mem, mem_size);

    const char* c = mem;
    const char* end = mem + mem_size;
    std::string_view plays;
    int song_pos = 1;
    int str_len = 0;

    while (song_pos <= songs && ++c < end)
    {
        if (*c == ' ')
        {
            plays = std::string_view(c - str_len, str_len);
            str_len = 0;
            ++c;
        }
        else if (*c == '\n')
        {
            auto listens = unsafe_strtol(plays);
            auto title = std::string_view(c - str_len, str_len);
            song_list.emplace_back(title, listens * song_pos++);
            str_len = 0;
            ++c;    
        }
        ++str_len;
    }
    return;
}

void print_songs(const std::vector<Song>& song_list, int no_songs)
{
    for (int i = 0; i < no_songs; ++i)
    {
        std::cout << song_list[i].name() << '\n';
    }
    return;
}

int main()
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

    std::ios::sync_with_stdio (false);
    std::string input;
    std::getline(std::cin, input);
    auto input_view = std::string_view(input); 
    int pos = input_view.find(" ");
    int no_songs = unsafe_strtol(input_view.substr(0, pos));
    int no_outputs = unsafe_strtol(input_view.substr(pos + 1));

    // Assume max 30 chars per title and 20 chars for number of plays + whitespaces
    size_t mem_size = no_songs * 50;
    char* string_area = static_cast<char*>(malloc(mem_size));

    std::vector<Song> song_list;
    parse_songs(no_songs, song_list, string_area, mem_size);
    stable_sort(song_list.begin(), song_list.end(), std::greater<Song>());
    print_songs(song_list, no_outputs);
    delete string_area;

    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::cout << "Ex. time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    return 0;
}