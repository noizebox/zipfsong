//*******************************************
// Spotify puzzle #2 - Zipf's song
// Gustav Andersson - 161015
// gustav.k.andersson@gmail.com
//*******************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>

class Song
{
public:
    Song(const std::string& name, int64_t rating) : _name(name), _zipf_rating(rating) {} ;
    ~Song() = default;

    const std::string& name() const {return _name;} ;
    int64_t            rating() const {return _zipf_rating;} ;
    friend bool operator< (const Song& lhs, const Song& rhs){ return lhs._zipf_rating < rhs._zipf_rating; };
    friend bool operator> (const Song& lhs, const Song& rhs){ return rhs < lhs; };

private:
    std::string   _name;
    int64_t       _zipf_rating;
};

void parse_songs(int songs, std::vector<Song>& song_list)
{
    song_list.reserve(songs);
    std::string input;
    input.reserve(100);
    for (int i = 1 ; i <= songs ; i++)
    {
        std::getline(std::cin, input);
        int pos = input.find(" ");
        int64_t listens = atol(input.substr(0, pos).data());
        song_list.emplace_back(input.substr(pos + 1), listens * i);
    }
    return;
}

void print_songs(const std::vector<Song>& song_list, int no_songs)
{
    for (int i = 0; i < no_songs ; ++i)
    {
        std::cout << song_list[i].name() <<  '\n';
    }
    return;
}

int main()
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

    std::ios::sync_with_stdio (false);
    std::string input;
    std::getline(std::cin, input);
    int pos = input.find(" ");
    int no_songs = atoi(input.substr(0, pos).c_str());
    int no_outputs = atoi(input.substr(pos + 1).c_str());

    std::vector<Song> song_list;
    parse_songs(no_songs, song_list);
    stable_sort(song_list.begin(), song_list.end(), std::greater<Song>());
    print_songs(song_list, no_outputs);
    
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::cout << "Ex. time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms\n";
    return 0;
}