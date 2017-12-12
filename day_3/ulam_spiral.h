#pragma once
#include <vector>
#include <iostream>
#include <utility>
#include <string>

class ulam_spiral
{
public:
	ulam_spiral(size_t size);
	ulam_spiral(const ulam_spiral& other) = default;
	ulam_spiral(ulam_spiral&& other) = default;
	ulam_spiral& operator=(const ulam_spiral& other) = default;
	ulam_spiral& operator=(ulam_spiral&& other) = default;
	~ulam_spiral() = default;

	int at(int x, int y) const;
	int get_value(int x, int y) const;
	bool contains(size_t number) const;
	std::pair<size_t, size_t> position_of_element(size_t element) const;
	std::string to_string() const;
	size_t get_size() const;

	friend std::ostream& operator<< (std::ostream& stream, const ulam_spiral& spiral);

private:
	void fill();
	void fill_concurrently();
	void fill_circuit(size_t line);
	void fill_upper_line(size_t line);
	void fill_left_line(size_t line);
	void fill_bottom_line(size_t line);
	void fill_right_line(size_t line);

	void set_value(size_t x, size_t y, int val);
	
	size_t collumns;
	std::vector<int> array;
	size_t value_in_vertial_row(size_t pos);
};

