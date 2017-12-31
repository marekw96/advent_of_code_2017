#include "Operations.h"

bool aoc::operation::equal(int left, int right)
{
	return left == right;
}

bool aoc::operation::equal_and_bigger(int left, int right)
{
	return left >= right;
}

bool aoc::operation::bigger(int left, int right)
{
	return left > right;
}

bool aoc::operation::equal_and_less(int left, int right)
{
	return left <= right;
}

bool aoc::operation::less(int left, int right)
{
	return left < right;
}

bool aoc::operation::not_equal(int left, int right)
{
	return left != right;
}
