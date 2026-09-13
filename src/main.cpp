#include <iostream>
#include <string_view>
#include "LivingRoom.h"

#include <cpr/cpr.h>

// Initialise connection
int get_home(){
	try{
		auto const host = "localhost";
		auto const port = "8080";
		auto const target = "/albums";
		int version = 11;

		net::io_context ioc;
		tcp::resolver resolver(ioc);
		beast::tcp_stream stream(ioc);

		//Look up domain name
		auto const results = resolver.resolve(host, port);
		stream.connect(results);

		http::request<http::string_body> req {http::verb::get, target, version};
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(stream, req);
		beast::flat_buffer buffer;
		http::response<http::dynamic_body> res;
		http::read(stream, buffer, res);

		std::cout << res << std::endl;

		//Close socket
		beast::error_code ec;
		stream.socket().shutdown(tcp::socket::shutdown_both, ec);
	}
	catch(std::exception const& e){
		std::cerr << "Error" << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int main(){
	cpr::Response r = cpr::Get(cpr::Url{"localhost:8080/"});
	std::cout << "SC: " << r.status_code << std::endl;
	std::cout << r.text << std::endl;
	return 0;
}
