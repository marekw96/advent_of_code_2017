#include "ulam_spiral.h"
#include <exception>
#include <algorithm>
#include <sstream>
#include <future>

#include <iostream>

ulam_spiral::ulam_spiral(size_t size) :
	collumns(size%2? size: size+1), array(std::max(collumns*collumns, 2u), 0)
{
	fill();
}

int ulam_spiral::at(int x, int y) const
{
	return array.at(x*collumns + y);
}

int ulam_spiral::get_value(int x, int y) const
{
	auto middle = collumns / 2;
	return at(middle + x, middle +y);
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
	auto x = position / collumns;
	auto y = position - x*collumns;
	return std::make_pair(x,y);
}

std::string ulam_spiral::to_string() const
{
	std::stringstream stream;
	for (size_t y = 0; y < collumns; ++y)
	{
		for (size_t x = 0; x < collumns; ++x)
		{
			stream << '\t' << at(x, y);
		}
		stream << '\n';
	}

	return stream.str();
}

size_t ulam_spiral::get_size() const
{
	return collumns;
}

std::ostream & operator<<(std::ostream & stream, const ulam_spiral & spiral)
{
	return stream << spiral.to_string();
}

void ulam_spiral::fill()
{
	if (collumns > 5)
	{
		fill_concurrently();
		return;
	}

	auto middle = collumns/2;

	for (size_t i = 0; i <= middle; ++i)
	{
		fill_circuit(i);
	}
}

void ulam_spiral::fill_concurrently()
{
	std::vector<std::future<void>> tasks;
	std::atomic<size_t> line = -1;

	auto task = [&line,this] (size_t collumns) -> void
	{
		size_t l;
		while ((l = ++line) <= collumns)
		{
			this->fill_circuit(l);
		}
	};

	int threads = 4;
	
	for(int i = 0; i < threads; ++i)
		tasks.push_back(std::async(task, collumns/2));

	for (auto &t : tasks)
		t.get();
}

void ulam_spiral::fill_circuit(size_t circuit)
{
	auto middle = collumns/2;
	
	if (circuit == 0)
	{
		set_value(middle, middle, 1);
		set_value(middle+1, middle, 2);
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
	auto value = value_in_vertial_row(line) - line;
	auto middle = collumns / 2;
	for (size_t i = 0; i <= line * 2; ++i)
	{
		set_value(middle + line - i, middle - line, value + i);
	}
}

void ulam_spiral::fill_left_line(size_t line)
{
	auto middle = collumns / 2;
	auto pos = middle - line;
	auto value = at(pos, pos);

	for (size_t i = 1; i <= line*2; ++i)
	{
		set_value(pos, pos + i, value + i);
	}
}

void ulam_spiral::fill_bottom_line(size_t line)
{
	auto middle = collumns / 2;
	auto value = at(middle - line, middle + line);

	for (size_t i = 1; i <= line * 2; ++i)
	{
		set_value(middle - line + i, middle + line, value + i);
	}
}

void ulam_spiral::fill_right_line(size_t line)
{
	auto middle = collumns / 2;
	auto value = at(middle + line, middle + line);

	for (size_t i = 1; i < (line+1) * 2; ++i)
	{
		set_value(middle + line + 1, middle + line - i + 1, value + i);
	}
}

void ulam_spiral::set_value(size_t x, size_t y, int val)
{
	array.at(x*collumns + y) = val;
}

size_t ulam_spiral::value_in_vertial_row(size_t pos)
{
	return  4 * pos*pos - pos + 1;
}


