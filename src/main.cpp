#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <iostream>
#include <string_view>
#include "LivingRoom.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

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
	get_home();
	LivingRoom lr {1};
	lr.add_album(0, "Hunky Dory", "David Bowie");
	lr.add_album(1, "Ziggy", "David Bowie");
	lr.add_album(2, "Pin-ups", "David Bowie");
	lr.add_album(3, "Blackstar", "David Bowie");

	std::array<std::string_view, 4> xs {lr.basic_display()};
	for(auto title: xs){
		std::cout << title << '\n';
	}
	return 0;
}
