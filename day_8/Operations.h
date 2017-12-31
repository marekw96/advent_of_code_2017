#pragma once

namespace aoc
{
	namespace operation
	{
		bool equal(int left, int right);	
		bool equal_and_bigger(int left, int right);
		bool bigger(int left, int right);
		bool equal_and_less(int left, int right);
		bool less(int left, int right);
		bool not_equal(int left, int right);
	}
}