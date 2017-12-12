#pragma once
#include <vector>
#include <iostream>
#include <utility>

class ulam_spiral
{
public:
	ulam_spiral(size_t size);
	int& at(int x, int y);
	int at(int x, int y) const;
	bool contains(size_t number) const;
	std::pair<size_t, size_t> position_of_element(size_t element) const;

	friend std::ostream& operator<< (std::ostream& stream, const ulam_spiral& spiral)
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
	void fill();
	void fill_circuit(size_t line);
	void fill_upper_line(size_t line);
	void fill_left_line(size_t line);
	void fill_bottom_line(size_t line);
	void fill_right_line(size_t line);
	
	std::vector<int> array;
	size_t collumns;
	size_t value_in_vertial_row(size_t pos);
};

