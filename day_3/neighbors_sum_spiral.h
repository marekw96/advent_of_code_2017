#pragma once
#include <vector>
#include <iostream>
#include <utility>

class neighbors_sum_spiral
{
public:
	neighbors_sum_spiral(size_t size);
	int& at(int x, int y);
	int at(int x, int y) const;
	int get_val(int x, int y) const;

	friend std::ostream& operator<< (std::ostream& stream, const neighbors_sum_spiral& spiral)
	{
		for (size_t y = 0; y < spiral.collumns; ++y)
		{
			for (size_t x = 0; x < spiral.collumns; ++x)
			{
				stream << '\t' << spiral.at(x, y);
			}
			stream << '\n';
		}

		return stream;
	}

private:
	enum class FILL_TYPE { INCRESE, DECRESE };
	void fill();
	void fill_circuit(size_t line);
	void fill_upper_line(size_t line);
	void fill_left_line(size_t line);
	void fill_bottom_line(size_t line);
	void fill_right_line(size_t line);

	std::vector<int> array;
	size_t collumns;
	size_t sum_neighbors(size_t x, size_t y) const;
};

