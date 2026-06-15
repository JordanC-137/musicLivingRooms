#include <iostream>
#include "Album.h"

int main(){
	Album a1 {1, "Hunky Dory", "David Bowie"};
	std::cout << a1.getTitle() << '\n';

	return 0;
}
