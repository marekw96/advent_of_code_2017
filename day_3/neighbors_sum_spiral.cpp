#include "neighbors_sum_spiral.h"

neighbors_sum_spiral::neighbors_sum_spiral(size_t size) :
	array(size*size, 0), collumns(size)
{
	fill();
}

int & neighbors_sum_spiral::at(int x, int y)
{
	return array[x*collumns + y];
}

int neighbors_sum_spiral::at(int x, int y) const
{
	return array[x*collumns + y];
}

int neighbors_sum_spiral::get_val(int x, int y) const
{
	if(x < 0 || y < 0 || x >= collumns || y >= collumns)
		return 0;

	return at(x,y);
}

void neighbors_sum_spiral::fill()
{
	auto middle = collumns / 2;

	for (size_t i = 0; i <= middle; ++i)
	{
		fill_circuit(i);
	}
}

void neighbors_sum_spiral::fill_circuit(size_t circuit)
{
	auto middle = collumns / 2;

	if (circuit == 0)
	{
		at(middle, middle) = 1;
		at(middle + 1, middle) = 1;
		return;
	}

	fill_upper_line(circuit);
	fill_left_line(circuit);
	fill_bottom_line(circuit);
	if (circuit < middle)
		fill_right_line(circuit);
}

void neighbors_sum_spiral::fill_upper_line(size_t line)
{
	auto middle = collumns / 2;

	for (size_t i = 0; i <= line * 2; ++i)
	{
		at(middle +line - i, middle - line) = sum_neighbors(middle + line - i, middle - line);
	}
}

void neighbors_sum_spiral::fill_left_line(size_t line)
{
	auto middle = collumns / 2;
	auto pos = middle - line;

	for (size_t i = 1; i <= line * 2; ++i)
	{
		at(pos, pos + i) = sum_neighbors(pos, pos + i);
	}
}

void neighbors_sum_spiral::fill_bottom_line(size_t line)
{
	auto middle = collumns / 2;

	for (size_t i = 1; i <= line * 2; ++i)
	{
		at(middle - line + i, middle + line) = sum_neighbors(middle - line + i, middle + line);
	}
}

void neighbors_sum_spiral::fill_right_line(size_t line)
{
	auto middle = collumns / 2;

	for (size_t i = 1; i <= (line + 1) * 2; ++i)
	{
		at(middle + line + 1, middle + line - i + 1) = sum_neighbors(middle + line + 1, middle + line - i + 1);
	}
}

size_t neighbors_sum_spiral::sum_neighbors(size_t x, size_t y) const
{
	size_t sum = 0;

	sum += get_val(x - 1 ,y - 1);
	sum += get_val(x, y - 1);
	sum += get_val(x + 1, y - 1);
	sum += get_val(x - 1, y);
	sum += get_val(x + 1, y);
	sum += get_val(x - 1, y + 1);
	sum += get_val(x, y + 1);
	sum += get_val(x + 1, y + 1);

	return sum;
}
