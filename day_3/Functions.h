#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <map>

namespace aoc
{
	std::string read_file(std::string file_name);
	std::vector<std::string> split_by_new_line(const std::string& input);

	void print_input(const std::vector<std::string>& lines);
	std::vector<std::string> split_words(const std::string& line);

	unsigned int count_valid_passwords(const std::vector<std::string>& lines);
	bool is_passphrase_valid(const std::string& phrase);
	bool is_word_in_set(const std::unordered_set<std::string>& set, const std::string& word);

	unsigned int count_valid_passwords_part_two(const std::vector<std::string>& lines);
	bool is_passphrase_valid_part_two(const std::string& line);
	bool could_be_rearranged(const std::string& s1, const std::string& s2);
	int count_letter(const std::string& word, char letter);
}