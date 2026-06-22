#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include <vector>
#include "Album.h"
#include <string_view>
#include <array>
#include <stddef.h>

class LivingRoom{
    int m_id;
    std::vector<Album> m_collection;

public:
    LivingRoom(int id);

    int add_album(int id, std::string title, std::string artist);

    std::array<std::string_view, 4>basic_display();

    std::vector<Album> getCollection(){ return m_collection; };
};

#endif