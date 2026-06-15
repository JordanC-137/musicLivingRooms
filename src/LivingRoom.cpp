#include "LivingRoom.h"

LivingRoom::LivingRoom(int id)
    : m_id{ id }
{
}

int LivingRoom::add_album(int id, std::string title, std::string artist)
{
    Album album{id, title, artist};
    m_collection.push_back(album);
    return 0;
}