#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <map>

namespace aoc
{
	std::string read_file(std::string file_name);
	std::vector<std::string> split_by_new_line(const std::string& input);
}