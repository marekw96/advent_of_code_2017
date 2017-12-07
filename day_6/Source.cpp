#include "Functions.h"
#include <iostream>

int main()
{
	auto input = aoc::read_file("input.txt");
	auto bank = aoc::make_bank(input);
	aoc::print_input(bank);

	auto cycles_part_one = aoc::redistribute(bank);
	std::cout << "Cycles in part one: " << cycles_part_one << std::endl;

	auto cycles_part_two = aoc::redistribute_part_two(bank);
	std::cout << "Cycles in part two: " << cycles_part_two << std::endl;

	return EXIT_SUCCESS;
}