#pragma once
#include <functional>
#include <string>

namespace aoc
{
	struct Instruction
	{
		std::string destination;
		std::string left_operand;
		int right_operand;
		int value;
		std::function<bool(int,int)> operation;
	};
}