#include "Memory.h"
#include <algorithm>

aoc::Memory::Memory()  : container{}, ever_max_value{INT_MIN}
{}

int aoc::Memory::get(const std::string& name)
{
	return this->is_in_container(name)? container[name] : 0;
}

void aoc::Memory::set(const std::string& name, int value)
{
	container[name] = value;
	this->set_ever_max_value(value);
}

std::pair<std::string, int> aoc::Memory::max_element()
{
	return *std::max_element(std::cbegin(container), std::cend(container), [](const auto& one, const auto& two){return one.second < two.second;});
}

int aoc::Memory::get_ever_max_value()
{
	return ever_max_value;
}

bool aoc::Memory::is_in_container(const std::string& name)
{
	return std::find_if(std::cbegin(container), std::cend(container), [&name](const auto& item){ return item.first == name;}) != std::cend(container);
}

void aoc::Memory::set_ever_max_value(int value)
{
	if(value > ever_max_value)
		ever_max_value = value;
}
