#include <iostream>
#include "Album.h"
#include "LivingRoom.h"

int main(){
	LivingRoom lr {1};
	lr.add_album(0, "Hunky Dory", "David Bowie");
	lr.add_album(1, "Ziggy", "David Bowie");
	lr.add_album(2, "Pin-ups", "David Bowie");
	lr.add_album(3, "Blackstar", "David Bowie");

	lr.basic_display();
	/*for(auto album: lr.getCollection()){
		std::cout << album.getTitle() << '\n';
	}*/
	return 0;
}
