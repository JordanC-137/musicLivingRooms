#include <iostream>
#include <string_view>
#include "LivingRoom.h"

#include <cpr/cpr.h>

long getRequest(std::string_view sv){
	cpr::Response r = cpr::Get(cpr::Url(sv),
	cpr::Header{{"accept", "application/json"}});
	return r.status_code;
}

int main(){
	int sc {getRequest("http://www.httpbin.org")};
	std::cout << "SC: " << sc << std::endl;
	return 0;
}
