#include <iostream>
#include "Functions.h"
#include "day_8.h"
#include "Instruction.h"
#include "Memory.h"
#include "Operations.h"

int main()
{
	auto input = aoc::read_file("input.txt");
	auto lines = aoc::split_by_new_line(input);	

	auto instructions = day_8::make_instructions_from_lines(lines);

	aoc::Memory memory;
	
	day_8::execute(memory, instructions);
	auto max_element = memory.max_element();

	std::cout << max_element.first << " = " << max_element.second <<  std::endl;
	std::cout << "ever max value " << memory.get_ever_max_value() << std::endl;

	return EXIT_SUCCESS;
}