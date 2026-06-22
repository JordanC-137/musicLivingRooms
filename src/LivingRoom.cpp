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

std::vector<std::string_view> LivingRoom::basic_display()
{
    int count {0};
    std::vector<std::string_view> result{};

    std::vector<Album>::iterator it{m_collection.begin()};
    while(count < 4 & it != m_collection.end()){
        auto title = it->getTitle();
        result.push_back(title);
        ++it;
        count++;
    }
    return result;
}