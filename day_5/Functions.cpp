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

std::vector<int> aoc::split_integers(const std::string& input)
{
	std::vector<int> integers;
	std::stringstream stream(input);
	int temp = 0;

	while (stream >> temp)
	{
		integers.push_back(temp);
	}

	return integers;
}

void aoc::print_input(const std::vector<int>& input)
{
	std::cout << "Input is: ";
	for (auto i : input)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

unsigned int aoc::calc_jumps(const std::vector<int>& jumps_ref)
{
	auto jumps = jumps_ref;
	unsigned int jumps_sum = 0;
	size_t pos = 0;
	auto items = jumps.size();
	size_t next_pos = 0;

	while (pos < items)
	{
		++jumps_sum;
		next_pos = aoc::jump_to(pos, jumps[pos]);
		++jumps[pos];
		pos = next_pos;
	}

	return jumps_sum;
}

size_t aoc::jump_to(size_t from, size_t value)
{
	return from + value;
}

unsigned int aoc::calc_jumps_part_two(const std::vector<int>& jumps_ref)
{
	auto jumps = jumps_ref;
	unsigned int jumps_sum = 0;
	size_t pos = 0;
	auto items = jumps.size();
	size_t next_pos = 0;

	while (pos < items)
	{
		++jumps_sum;
		next_pos = aoc::jump_to(pos, jumps[pos]);
		if (jumps[pos] >= 3)
		{
			--jumps[pos];
		}
		else
		{
			++jumps[pos];
		}
		pos = next_pos;
	}

	return jumps_sum;
}
