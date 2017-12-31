#include "day_8.h"

#include <sstream>
#include "Operations.h"

void day_8::execute(aoc::Memory & memory, const aoc::Instruction & instruction)
{
	int left_value = memory.get(instruction.left_operand);

	if (instruction.operation(left_value, instruction.right_operand))
	{
		int destination_value = memory.get(instruction.destination);
		memory.set(instruction.destination, destination_value + instruction.value);
	}
}

aoc::Instruction day_8::make_instruction_from_line(const std::string & line)
{
	
	day_8::parser::STATE state = day_8::parser::STATE::DESTINATION;

	aoc::Instruction instruction;

	if(line.empty())
		return instruction;

	std::stringstream buffer;

	auto size = line.size();

	for(unsigned i = 0; i <= size; ++i)
	{
		char letter;
		if(i == size)
			letter = ' ';
		else
			letter = line[i];
		
		if (letter == ' ')
		{
			day_8::parser::parse(instruction, buffer, state, i);
		}
		else
			buffer.put(letter);
	}

	return instruction;
}

std::vector<aoc::Instruction> day_8::make_instructions_from_lines(const std::vector<std::string>& lines)
{
	std::vector<aoc::Instruction> instructions;
	for (const auto& line : lines)
	{
		instructions.emplace_back(day_8::make_instruction_from_line(line));
	}

	return instructions;
}

void day_8::execute(aoc::Memory & memory, const std::vector<aoc::Instruction>& instructions)
{
	for (const auto& instruction : instructions)
	{
		day_8::execute(memory, instruction);
	}
}

void day_8::parser::parse(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state, unsigned & i)
{
	switch (state)
	{
		case day_8::parser::STATE::DESTINATION:
		day_8::parser::handle_destination(instruction, buffer, state);
		break;
		case day_8::parser::STATE::VALUE_TYPE:
		day_8::parser::handle_value_type(instruction, buffer, state);
		break;
		case day_8::parser::STATE::VALUE:
		day_8::parser::handle_value(instruction, buffer, state, i);
		break;
		case day_8::parser::STATE::LEFT_OPERAND:
		day_8::parser::handle_left_operand(instruction, buffer, state);
		break;
		case day_8::parser::STATE::OPERATION:
		day_8::parser::handle_operation(instruction, buffer, state);
		break;
		case day_8::parser::STATE::RIGHT_OPERAND:
		day_8::parser::handle_right_operand(instruction, buffer, state);
		break;
	}
}

void day_8::parser::handle_destination(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state)
{
	instruction.destination = buffer.str();
	buffer.str(std::string());
	state = day_8::parser::STATE::VALUE_TYPE;
}

void day_8::parser::handle_value_type(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state)
{
	if (buffer.str() == "dec")
		instruction.value = -1;
	else
		instruction.value = 1;
	buffer.str(std::string());
	state = day_8::parser::STATE::VALUE;
}

void day_8::parser::handle_value(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state, unsigned & i)
{
	instruction.value = std::stoi(buffer.str()) * instruction.value;
	buffer.str(std::string());
	state = day_8::parser::STATE::LEFT_OPERAND;
	i += std::string("if ").size();
}

void day_8::parser::handle_left_operand(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state)
{
	instruction.left_operand = buffer.str();
	buffer.str(std::string());
	state = day_8::parser::STATE::OPERATION;
}

void day_8::parser::handle_operation(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state)
{
	std::string op = buffer.str();
	if (op == "==")
		instruction.operation = aoc::operation::equal;
	else if (op == ">=")
		instruction.operation = aoc::operation::equal_and_bigger;
	else if (op == "<=")
		instruction.operation = aoc::operation::equal_and_less;
	else if (op == ">")
		instruction.operation = aoc::operation::bigger;
	else if (op == "<")
		instruction.operation = aoc::operation::less;
	else if (op == "!=")
		instruction.operation = aoc::operation::not_equal;
	buffer.str(std::string());
	state = day_8::parser::STATE::RIGHT_OPERAND;
}

void day_8::parser::handle_right_operand(aoc::Instruction & instruction, std::stringstream & buffer, day_8::parser::STATE & state)
{
	instruction.right_operand = std::stoi(buffer.str());
	buffer.str(std::string());
}
