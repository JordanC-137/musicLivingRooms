#include <iostream>
#include <unordered_set>
#include "Album.h"
#include "LivingRoom.h"

int main(){
	LivingRoom lr {1};
	lr.add_album(0, "Hunky Dory", "David Bowie");
	lr.add_album(1, "Ziggy", "David Bowie");
	lr.add_album(2, "Pin-ups", "David Bowie");
	lr.add_album(3, "Blackstar", "David Bowie");

	std::array<std::string_view, 4> xs {lr.basic_display()};
	for(auto title: xs){
		std::cout << title << '\n';
	}
	Album a1{0, "Hunky Dory", "David Bowie"};
	//std::unordered_set<Album> Set{a1};
	std::cout << std::hash(a1);
	return 0;
}
