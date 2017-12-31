#include "Functions.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <algorithm>

std::string aoc::read_file(std::string file_name)
{
	std::ifstream file(file_name);
	return std::string((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
}

std::vector<std::string> aoc::split_by_new_line(const std::string & input)
{
	std::stringstream stream(input);
	std::vector<std::string> strings;
	std::string temp;
	while (std::getline(stream, temp))
	{
		strings.emplace_back(std::move(temp));
	}

	return strings;
}