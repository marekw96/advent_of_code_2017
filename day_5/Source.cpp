#include "Functions.h"
#include <iostream>

int main()
{
	auto input = aoc::read_file("input.txt");
	auto jumps = aoc::split_integers(input);
	aoc::print_input(jumps);
	
	auto jumps_count_one = aoc::calc_jumps(jumps);
	std::cout <<"Jumps count part one: " << jumps_count_one << std::endl;

	auto jumps_count_two = aoc::calc_jumps_part_two(jumps);
	std::cout << "Jumps count part two: " << jumps_count_two << std::endl;


	return EXIT_SUCCESS;
}