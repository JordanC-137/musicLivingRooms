#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include <vector>
#include "Album.h"

class LivingRoom{
    int m_id;
    std::vector<Album> m_collection;

public:
    LivingRoom(int id);

    int add_album(int id, std::string title, std::string artist);
};

#endif