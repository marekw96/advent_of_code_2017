#include <iostream>
#include "ulam_spiral.h"
#include "aoc.h"
#include "neighbors_sum_spiral.h"

int main()
{
	int number = 347991;

	ulam_spiral spiral(1001);
	auto pos_of_1 = spiral.position_of_element(1);
	auto pos_of_347991 = spiral.position_of_element(number);
	std::cout << "Manhatan distance between 1 and " << number << " is " << aoc::manhattan_distance(pos_of_1, pos_of_347991);
	std::cout << std::endl;
	std::cout << "Neighbors sum spiral is ";
	std::cout << std::endl;
	neighbors_sum_spiral nss(9);
	std::cout << nss;

	return EXIT_SUCCESS;
}