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

aoc::bank aoc::make_bank(const std::string& input)
{
	return aoc::split_integers(input);
}

unsigned int aoc::redistribute(const aoc::bank& bank_ref)
{
	auto bank = bank_ref;
	unsigned int cycles = 0;
	std::unordered_set<std::string> occured_banks;
	size_t biggest_bank = 0;

	while (!aoc::is_bank_in_set(occured_banks, aoc::to_string(bank)))
	{
		occured_banks.emplace(aoc::to_string(bank));
		biggest_bank = aoc::bank_with_most_items(bank);
		aoc::redistribute(bank,  biggest_bank);
		++cycles;
	}
	

	return cycles;
}

size_t aoc::bank_with_most_items(const aoc::bank & bank)
{
	size_t id = 0;
	int max = 0;
	size_t id_max = 0;
	for(auto i : bank)
	{
		if (max < i)
		{
			max = i;
			id_max = id;
		}
		++id;
	}

	return id_max;
}

bool aoc::is_bank_in_set(const std::unordered_set<std::string>& set, const std::string& word)
{
	return set.find(word) != set.cend();
}

void aoc::redistribute(aoc::bank& bank, size_t id)
{
	size_t pos = id+1;
	auto last_id = bank.size();
	auto value = bank[id];
	bank[id] = 0;

	while (value != 0)
	{
		if(pos == last_id)
			pos = 0;
		++bank[pos++];
		--value;
	}
}

std::string aoc::to_string(const bank & bank)
{
	std::stringstream stream;
	for (const auto& i : bank)
	{
		stream << i << " ";
	}

	return stream.str();
}

unsigned int aoc::redistribute_part_two(const aoc::bank & bank_ref)
{
	auto bank = bank_ref;
	unsigned int cycles = 0;
	std::map<std::string, int> occured_banks;
	size_t biggest_bank = 0;

	while (!aoc::is_bank_in_map(occured_banks, aoc::to_string(bank)))
	{
		occured_banks.emplace(aoc::to_string(bank), cycles);
		biggest_bank = aoc::bank_with_most_items(bank);
		aoc::redistribute(bank, biggest_bank);
		++cycles;
	}


	return cycles - occured_banks[aoc::to_string(bank)];
}

bool aoc::is_bank_in_map(const std::map<std::string, int>& set, const std::string & word)
{
	return set.find(word) != set.cend();
}
