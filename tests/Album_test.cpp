#include "Album.h"
#include <gtest/gtest.h>

TEST(AlbumTest, Title)
{
    Album album{1, "Hunky Dory", "David Bowie"};
    ASSERT_EQ(album.getTitle(), "Hunky Dory");
}