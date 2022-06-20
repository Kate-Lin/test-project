#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "application.hpp"
#include <string>
#include <chrono>
#include <vector>
#include <cstring>
#include <fstream>
using std::string;

int main(int argc, char *argv[])
{
	string out_json;
	add_key("1","123123",out_json);
	std::cout << out_json << std::endl;
	add_key("2","345345",out_json);
	std::cout << out_json << std::endl;
	return 0;
}