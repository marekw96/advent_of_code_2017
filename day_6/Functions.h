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
	
	using bank = std::vector<int>;
	aoc::bank make_bank(const std::string& input);
	unsigned int redistribute(const aoc::bank& bank);
	size_t bank_with_most_items(const aoc::bank& bank);
	bool is_bank_in_set(const std::unordered_set<std::string>& set, const std::string& word);
	void redistribute(aoc::bank& bank, size_t id);
	std::string to_string(const bank& bank);

	unsigned int redistribute_part_two(const aoc::bank& bank);
	bool is_bank_in_map(const std::map<std::string, int>& set, const std::string& word);
}