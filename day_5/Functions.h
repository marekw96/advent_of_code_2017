#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <map>

namespace aoc
{
	std::string read_file(std::string file_name);
	std::vector<int> split_integers(const std::string& input);
	void print_input(const std::vector<int>& input);

	unsigned int calc_jumps(const std::vector<int>& jumps);
	size_t jump_to(size_t from, size_t value);

	unsigned int calc_jumps_part_two(const std::vector<int>& jumps);
}