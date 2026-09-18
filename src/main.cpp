#include <iostream>
#include <string_view>
#include <unordered_map>
#include "LivingRoom.h"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

long postRequest(std::string_view sv){
	std::unordered_map<std::string, std::string> map;
	map.emplace("title", "Ziggy Stardust");
	json json_m(map);
	cpr::Response r = cpr::Post(cpr::Url{sv},
						cpr::Header{{"Content-Type", "application/json"}},
						cpr::Body{json_m.dump()});
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
