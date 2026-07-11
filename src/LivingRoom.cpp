#include "LivingRoom.h"

LivingRoom::LivingRoom(int id)
    : m_id{ id }
{
}

int LivingRoom::add_album(int id, std::string title, std::string artist)
{
    m_collection.emplace(id, title, artist);
    return 0;
}

std::array<std::string_view, 4> LivingRoom::basic_display()
{
    int count {0};
    std::array<std::string_view, 4> result{"", "", "", ""};

    std::unordered_set<Album, Hasher>::iterator it{m_collection.begin()};
    while(count < 4 & it != m_collection.end()){
        auto title = it->getTitle();
        result[count] = title;
        it++;
        count++;    
    }

    return result;
}