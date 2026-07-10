#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <string_view>

class Album{
    int m_id{};
    std::string m_title{};
    std::string m_artist{};

public:

    Album(int id, std::string title, std::string artist);

    std::string_view getTitle() const { return m_title; };

    bool operator==(const Album& otherAlbum) const;

};

namespace std {
    template<>
    struct hash<Album>{
        size_t operator()(const Album& album);
    };
}

#endif