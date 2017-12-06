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

void aoc::print_input(const std::vector<std::string>& lines)
{
	std::cout << "Input is" << std::endl;
	for (const auto& line : lines)
	{
		std::cout << '\t' << line << std::endl;
	}
}

unsigned int aoc::count_valid_passwords(const std::vector<std::string>& lines)
{
	unsigned int number_of_valid = 0;

	for (const auto& line : lines)
	{
		if(aoc::is_passphrase_valid(line))
			++number_of_valid;
	}

	return number_of_valid;
}

bool aoc::is_passphrase_valid(const std::string& phrase)
{
	std::vector<std::string> words = aoc::split_words(phrase);
	std::unordered_set<std::string> used_words;
	
	for (const auto& word : words)
	{
		if (aoc::is_word_in_set(used_words, word))
		{
			return false;
		}
		used_words.emplace(word);
	}

	return true;
}

std::vector<std::string> aoc::split_words(const std::string& line)
{
	std::vector<std::string> words;
	std::stringstream stream(line);
	std::string temp;

	while (stream >> temp)
	{
		words.emplace_back(temp);
	}

	return words;
}

bool aoc::is_word_in_set(const std::unordered_set<std::string>& set, const std::string& word)
{
	return set.find(word) != set.cend();
}

unsigned int aoc::count_valid_passwords_part_two(const std::vector<std::string>& lines)
{
	unsigned int count = 0;

	for (const auto& line : lines)
	{
		if(is_passphrase_valid_part_two(line))
			++count;
	}

	return count;
}

bool aoc::is_passphrase_valid_part_two(const std::string & line)
{
	std::vector<std::string> words = aoc::split_words(line);
	std::unordered_set<std::string> sorted_words;

	for (auto& word : words)
	{
		std::sort(word.begin(), word.end());
		if (aoc::is_word_in_set(sorted_words, word))
		{
			return false;
		}
		sorted_words.emplace(word);
	}

	return true;
}
