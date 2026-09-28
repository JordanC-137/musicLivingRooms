#include <iostream>
#include <string_view>
#include <unordered_map>
#include "LivingRoom.h"

#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>

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

void printSomething(Fl_Widget *widget, void* data){
	std::cerr << "Button pressed!";
}

void buttonGetRequest(Fl_Widget *widget, void* data){
	getRequest("http://localhost:8080");
}

int main(){
	//Define window
	Fl_Window *window = new Fl_Window(340, 180);


	Fl_Button *button = new Fl_Button(50, 50, 100, 100, "Press!");
	button->callback(printSomething);
	//button->callback(buttonGetRequest);
	window->end();
	window->show();
	return Fl::run();
}
