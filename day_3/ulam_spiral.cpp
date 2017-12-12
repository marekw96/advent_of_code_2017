#include "ulam_spiral.h"
#include <exception>
#include <algorithm>

ulam_spiral::ulam_spiral(size_t collumns) :
	array(collumns*collumns, 0), collumns(collumns)
{
	fill();
}

int& ulam_spiral::at(int x, int y)
{
	return array[x*collumns + y];
}

int ulam_spiral::at(int x, int y) const
{
	return array[x*collumns + y];
}

bool ulam_spiral::contains(size_t number) const
{
	return std::find(std::cbegin(this->array),std::cend(this->array), number) != std::cend(this->array);
}

std::pair<size_t, size_t> ulam_spiral::position_of_element(size_t element) const
{
	auto position_iterator = std::find(std::cbegin(this->array), std::cend(this->array), element);
	if(position_iterator == std::cend(this->array))
		throw std::runtime_error("not found");

	auto position = position_iterator - std::cbegin(this->array);
	auto y = position / collumns;
	auto x = position - y*collumns;
	return std::make_pair(x,y);
}

void ulam_spiral::fill()
{
	auto middle = collumns/2;
	
	for (size_t i = 0; i <= middle; ++i)
	{
		fill_circuit(i);
	}
}

void ulam_spiral::fill_circuit(size_t circuit)
{
	auto middle = collumns/2;
	
	if (circuit == 0)
	{
		at(middle, middle) = 1;
		at(middle+1, middle) = 2;
		return;
	}
	
	fill_upper_line(circuit);
	fill_left_line(circuit);
	fill_bottom_line(circuit);
	if(circuit < middle)
		fill_right_line(circuit);
}

void ulam_spiral::fill_upper_line(size_t line)
{
	auto value = value_in_vertial_row(line);
	auto middle = collumns / 2;
	for (size_t i = 0; i <= line; ++i)
	{
		at(middle - i, middle - line) = value +i;
	}
	for (size_t i = 0; i <= line; ++i)
	{
		at(middle + i, middle - line) = value - i;
	}
}

void ulam_spiral::fill_left_line(size_t line)
{
	auto middle = collumns / 2;
	auto value = at(middle - line, middle - line);
	auto pos = middle - line;

	for (size_t i = 1; i <= line*2; ++i)
	{
		at(pos, pos + i) = value + i;
	}
}

void ulam_spiral::fill_bottom_line(size_t line)
{
	auto middle = collumns / 2;
	auto value = at(middle - line, middle + line);

	for (size_t i = 1; i <= line * 2; ++i)
	{
		at(middle - line +i, middle+line) = value + i;
	}
}

void ulam_spiral::fill_right_line(size_t line)
{
	auto middle = collumns / 2;
	auto value = at(middle + line, middle + line);

	for (size_t i = 1; i <= (line+1) * 2; ++i)
	{
		at(middle + line + 1, middle + line - i + 1) = value + i;
	}
}

size_t ulam_spiral::value_in_vertial_row(size_t pos)
{
	return  4 * pos*pos - pos + 1;
}
