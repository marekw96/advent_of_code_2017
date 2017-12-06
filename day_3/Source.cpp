#include <iostream>
#include "Functions.h"

int main()
{
	auto input = aoc::read_file("input.txt");
	auto lines = aoc::split_by_new_line(input);
	aoc::print_input(lines);

	auto valid_part_one = aoc::count_valid_passwords(lines);
	std::cout<< "Valid passphrases: " << valid_part_one << std::endl;


	// TODO: doesn't work :/
	auto valid_part_two = aoc::count_valid_passwords_part_two(lines);
	std::cout << "Valid passphrases part two: " << valid_part_two << std::endl;

	return EXIT_SUCCESS;
}