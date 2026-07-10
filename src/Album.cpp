#include "Album.h"

Album::Album(int id, std::string title, std::string artist):
    m_id{id}, m_title{title}, m_artist{artist}{}

bool Album::operator==(const Album& otherAlbum) const {
    return m_title == otherAlbum.getTitle();
}

namespace std {
    template<>
    struct hash<Album>{
        size_t operator()(const Album& album){
            return std::hash<std::string_view>{}(album.getTitle());
        }
    };
}