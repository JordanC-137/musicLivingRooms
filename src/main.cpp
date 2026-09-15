#include <iostream>
#include <string_view>
#include "LivingRoom.h"

#include <cpr/cpr.h>

long postRequest(std::string_view sv){
	cpr::Response r = cpr::Post(cpr::Url{sv},
						cpr::Header{{"Content-Type", "application/json"}},
						cpr::Body{"{\"title\":\"Ziggy Stardust\"}"});
	std::cout << r.text << std::endl;
	return r.status_code;
}

long getRequest(std::string_view sv){
	cpr::Response r = cpr::Get(cpr::Url(sv),
	cpr::Header{{"accept", "application/json"}});
	return r.status_code;
}

int main(){
	int sc {postRequest("localhost:8080/albums")};
	std::cout << "SC: " << sc << std::endl;
	return 0;
}
