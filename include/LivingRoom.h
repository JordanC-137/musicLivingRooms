#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include <vector>
#include "Album.h"
#include <string_view>

class LivingRoom{
    int m_id;
    std::vector<Album> m_collection;

public:
    LivingRoom(int id);

    int add_album(int id, std::string title, std::string artist);

    std::vector<std::string_view> basic_display();

};

#endif