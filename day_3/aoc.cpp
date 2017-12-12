#include "aoc.h"
#include <cmath>

size_t aoc::manhattan_distance(const std::pair<size_t, size_t>& point_a, const std::pair<size_t, size_t>& point_b)
{
	return std::abs(static_cast<int>(point_a.first) - static_cast<int>(point_b.first)) + 
		std::abs(static_cast<int>(point_a.second) - static_cast<int>(point_b.second));
}
