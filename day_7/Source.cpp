#include "Functions.h"
#include "day7.h"
#include <iostream>
#include <algorithm>

int main()
{
	auto input = aoc::read_file("input.txt");
	auto lines = aoc::split_by_new_line(input);
	
	auto nodes = day7::lines_to_nodes(lines);
	day7::set_parents(nodes);

	auto node_without_parent = std::find_if(std::begin(nodes), std::end(nodes), [](const auto& node){
		return node.parent == nullptr;
	});

	if (node_without_parent != std::cend(nodes))
	{
		std::cout << "Found " << node_without_parent->name << std::endl;
	}

	std::cout << std::endl << std::endl;


	return EXIT_SUCCESS;
}