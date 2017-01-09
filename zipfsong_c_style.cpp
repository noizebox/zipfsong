//*******************************************
// Spotify puzzle #2 - Zipf's song
// Gustav Andersson - 161206
// gustav.k.andersson@gmail.com
//
// Solved by dumping the input from memory quickly and without processing.
// Then interating through it in a raw c-like fashion. No strings are copied
// so sorting is cheap. Not elegant in a c++11 way, but very fast.
//
// Now also prints by putting chars directly on cout and thus avoiding 
// STL's slow stream handling.  
//*******************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>

class Song
{
public:
    Song(const char* name, int64_t rating) : _name(name), _zipf_rating(rating) {} ;
    ~Song() = default;
    const char* name() const {return _name;} ;
    friend bool operator< (const Song& lhs, const Song& rhs){ return lhs._zipf_rating < rhs._zipf_rating; };
    friend bool operator> (const Song& lhs, const Song& rhs){ return rhs < lhs; };
private:
    int64_t       _zipf_rating;
    const char*   _name;
};

void parse_songs(const int songs, std::vector<Song>& song_list, char* mem, size_t mem_size)
{
    song_list.reserve(songs);
    std::cin.read(mem, mem_size);

    char* c = mem;
    char* plays = mem;
    char* title = nullptr;
    char* end = mem + mem_size;
    int song_pos = 1;
    while (c < end && song_pos <= songs)
    {
        if (*c == ' ')
        {
            title = c + 1;
            *c = 0;
        }
        else if (*c == '\n')
        {
            int64_t listens = atol(plays);
            song_list.push_back(Song(title, listens * song_pos++));
            plays = c + 1;
            *c = 0;
        }
        ++c;
    }
    *--c = 0;
    return;
}

void print_songs(const std::vector<Song>& song_list)
{
    for (std::vector<Song>::const_iterator i = song_list.begin(); i < song_list.end(); ++i)
    {
        const char* name = i->name();
        while (*name != 0)
        {
            std::cout.put(*name++);
        }
        std::cout.put('\n');
    }
    return;
}

int main()
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

    std::cin.sync_with_stdio (false);
    std::string input;
    std::getline(std::cin, input);
    int pos = input.find(" ");
    int no_songs = atoi(input.substr(0, pos).c_str());
    int no_outputs = atoi(input.substr(pos + 1).c_str());

    size_t mem_size = no_songs * 50; // max 30 chars per title and 20 chars for number of plays and whitespaces should be enough
    char* string_area = static_cast<char*>(malloc(mem_size));

    std::vector<Song> song_list;
    parse_songs(no_songs, song_list, string_area, mem_size);
    stable_sort(song_list.begin(), song_list.end(), std::greater<Song>());
    print_songs(song_list);
    delete string_area;

    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::cout << "Ex. time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms" << std::endl;
    return 0;
}