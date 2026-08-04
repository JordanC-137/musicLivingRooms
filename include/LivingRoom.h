#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include <vector>
#include "Album.h"
#include <string_view>
#include <array>
#include <stddef.h>
#include <unordered_set>

struct Hasher{
    size_t operator()(const Album& album) const {
            return std::hash<std::string_view>{}(album.getTitle());
    }
};

class LivingRoom{
    int m_id;
    std::unordered_set<Album, Hasher> m_collection;
public:
    LivingRoom(int id);

    int add_album(int id, std::string title, std::string artist);

    std::array<std::string_view, 4>basic_display();

    std::unordered_set<Album, Hasher> getCollection(){ return m_collection; };
};

#endif