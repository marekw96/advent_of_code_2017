#pragma once

#include "Memory.h"
#include "Instruction.h"
#include <vector>
#include <sstream>

namespace day_8
{
	void execute(aoc::Memory& memory, const aoc::Instruction& instruction);	
	aoc::Instruction make_instruction_from_line(const std::string& line);
	std::vector<aoc::Instruction> make_instructions_from_lines(const std::vector<std::string>& lines);
	void execute(aoc::Memory& memory, const std::vector<aoc::Instruction>& instructions);
	namespace parser
	{
		enum class STATE { DESTINATION, VALUE_TYPE, VALUE, LEFT_OPERAND, RIGHT_OPERAND, OPERATION };
		void parse(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state, unsigned& i);
		void handle_destination(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state);
		void handle_value_type(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state);
		void handle_value(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state, unsigned& i);
		void handle_left_operand(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state);
		void handle_operation(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state);
		void handle_right_operand(aoc::Instruction& instruction, std::stringstream& buffer, day_8::parser::STATE& state);
	}
}