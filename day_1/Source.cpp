#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>

unsigned int calc_captcha(const std::string& input);
unsigned int calc_captcha_part_two(const std::string& input);
void prepare_input(std::string& input);
void prepare_to_part_two(std::string& input);
int letter_to_int(char letter);
char get_char(const std::string& input, size_t pos);
std::string read_file(std::string file_name);

int main()
{
	auto input = read_file("input.txt");
	//Part one
	prepare_input(input);
	auto captcha = calc_captcha(input);
	//Part two
	prepare_to_part_two(input);
	auto captcha_part_two = calc_captcha_part_two(input);

	std::cout << "Input is " << input << std::endl;
	std::cout << "Captcha is " << captcha << std::endl;
	std::cout << "Captcha of part two is " << captcha_part_two << std::endl;


	return EXIT_SUCCESS;
}

unsigned int calc_captcha(const std::string & input)
{
	unsigned int captcha = 0;
	char last_digit = 0;
	for (const auto& digit : input)
	{
		if (last_digit == digit)
		{
			captcha += letter_to_int(digit);
		}
		last_digit = digit;
	}
	return captcha;
}

unsigned int calc_captcha_part_two(const std::string& input)
{
	unsigned int pos;
	auto end = std::cend(input);
	auto item = std::cbegin(input);
	unsigned int half_size = input.length()/2;
	char pair_digit = 0;
	char digit = 0;
	unsigned int captcha = 0;

	for (pos = 0; item != end; ++item, ++pos)
	{
		digit = *item;
		pair_digit = get_char(input, pos + half_size);
		if (pair_digit == digit)
		{
			captcha += letter_to_int(digit);
		}
	}

	return captcha;
}

void prepare_input(std::string& input)
{
	input += input[0];
}

void prepare_to_part_two(std::string & input)
{
	input.pop_back();
}

int letter_to_int(char letter)
{
	return letter - '0';
}

char get_char(const std::string& input, size_t pos)
{
	return input[input.length() - 1 < pos ? pos - input.length() : pos];
}

std::string read_file(std::string file_name)
{
	std::ifstream file(file_name);
	return std::string((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
}
