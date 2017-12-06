#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <memory>
#include <climits>
#include <algorithm>

std::string read_file(std::string file_name);
std::vector<std::string> split_by_new_line(const std::string& input);
void print_input(const std::vector<std::string>& input);
unsigned int calc_checksum(const std::vector<std::string>& input);
int min_max_difference(const std::string& line);
std::vector<int> convert_to_integers(const std::string& line);
unsigned int calc_checksum_part_two(const std::vector<std::string>& input);
bool divides(int a, int b);
int result_of_line(const std::vector<int> line);

int main()
{
	auto input = read_file("input.txt");
	auto lines = split_by_new_line(input);
	print_input(lines);

	auto checksum = calc_checksum(lines);
	std::cout << "Checksum is " << checksum << std::endl;

	auto checksum_part_two = calc_checksum_part_two(lines);
	std::cout << "Checksum part two is " << checksum_part_two << std::endl;

	return EXIT_SUCCESS;
}

std::string read_file(std::string file_name)
{
	std::ifstream file(file_name);
	return std::string((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
}

std::vector<std::string> split_by_new_line(const std::string& input)
{
	std::stringstream stream(input);
	std::vector<std::string> strings;
	std::string temp;
	while(std::getline(stream, temp))
	{
		strings.emplace_back(std::move(temp));
	}

	return strings;
}

void print_input(const std::vector<std::string>& input)
{
	std::cout << "Input is" << std::endl;
	for (const auto& line : input)
	{
		std::cout << "\t" << line << std::endl;
	}
}

unsigned int calc_checksum(const std::vector<std::string>& input)
{
	unsigned int checksum = 0;

	for (const auto& line : input)
	{
		checksum += min_max_difference(line);
	}

	return checksum;
}

int min_max_difference(const std::string & line)
{
	auto integers = convert_to_integers(line);

	auto min_max = std::minmax_element(std::cbegin(integers), std::cend(integers));

	return min_max.second - min_max.first;
}

std::vector<int> convert_to_integers(const std::string & line)
{
	std::vector<int> integers;
	std::stringstream stream(line);
	int temp = 0;

	while (stream >> temp)
	{
		integers.push_back(temp);
	}

	return integers;
}

unsigned int calc_checksum_part_two(const std::vector<std::string>& input)
{
	unsigned int checksum = 0;

	for (const auto& line : input)
	{
		checksum += result_of_line(convert_to_integers(line));
	}

	return checksum;
}

bool divides(int a, int b)
{
	return a%b == 0;
}

int result_of_line(const std::vector<int> line)
{
	for (int a : line)
	{
		for (int b : line)
		{
			if (a != b)
			{
				if (divides(a, b))
				{
					return a/b;
				}
			}
		}
	}
	return 0;
}
