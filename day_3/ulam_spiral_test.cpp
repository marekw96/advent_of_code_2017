#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "ulam_spiral.h"
#include <memory>
#include <utility>
#include <sstream>

std::unique_ptr<ulam_spiral> spiral;

TEST_CASE("Generating ulam spiral (1 row&collumnt)", "[c-tor]")
{
	REQUIRE_NOTHROW(spiral = std::make_unique<ulam_spiral>(1));
}

TEST_CASE("Generate ulam spiral of even number", "[c-tor]")
{
	REQUIRE_NOTHROW(spiral = std::make_unique<ulam_spiral>(10));
	REQUIRE(spiral->get_size() == 11);
}

TEST_CASE("Generating ulam spiral (7 rows&collumns)", "[c-tor]")
{
	REQUIRE_NOTHROW(spiral = std::make_unique<ulam_spiral>(7));
}

TEST_CASE("Check all positions", "[check positions]")
{
	int correct_values[7][7] = {{37,36,35,34,33,32,31},
								{38,17,16,15,14,13,30},
								{39,18, 5, 4, 3,12,29},
								{40,19, 6, 1, 2,11,28},
								{41,20, 7, 8, 9,10,27},
								{42,21,22,23,24,25,26},
								{43,44,45,46,47,48,49}};

	for (int y = 0; y < 7; ++y)
	{
		for (int x = 0; x < 7; ++x)
		{
			REQUIRE(spiral->at(x,y) == correct_values[y][x]);
		}
	}
}

TEST_CASE("Check contains - false", "[contains]")
{
	REQUIRE_FALSE(spiral->contains(50) == true);
}

TEST_CASE("Check contains - true", "[constains]")
{
	REQUIRE(spiral->contains(19) == true);
}

TEST_CASE("Position of element (47)", "[position_of_element]")
{
	auto correct = std::make_pair<size_t,size_t>(4,6);
	auto position = spiral->position_of_element(47);
	REQUIRE(position == correct);
}

TEST_CASE("Position of not existing element(51)", "[position_of_element]")
{
	REQUIRE_THROWS(spiral->position_of_element(51));
}

TEST_CASE("Get elemnt from position", "[at]")
{
	REQUIRE(spiral->at(2,2) == 5);
}

TEST_CASE("Get elemnt from position out of spiral", "[at]")
{
	REQUIRE_THROWS(spiral->at(10, 10));
}

TEST_CASE("Make string", "[to_string]")
{
auto correct =	"	37	36	35	34	33	32	31\n"
				"	38	17	16	15	14	13	30\n"
				"	39	18	5	4	3	12	29\n"
				"	40	19	6	1	2	11	28\n"
				"	41	20	7	8	9	10	27\n"
				"	42	21	22	23	24	25	26\n"
				"	43	44	45	46	47	48	49\n";

REQUIRE(spiral->to_string() == correct);
}

TEST_CASE("output operator" "operator<<")
{
auto correct =	"	37	36	35	34	33	32	31\n"
				"	38	17	16	15	14	13	30\n"
				"	39	18	5	4	3	12	29\n"
				"	40	19	6	1	2	11	28\n"
				"	41	20	7	8	9	10	27\n"
				"	42	21	22	23	24	25	26\n"
				"	43	44	45	46	47	48	49\n";
std::stringstream stream;
	stream << *spiral;
	REQUIRE(stream.str() == correct);
}

TEST_CASE("get value from middle (0,0)", "[get_value]")
{
	REQUIRE(spiral->get_value(0,0) == 1);
}

TEST_CASE("get value from middle (2,3)", "[get_value]")
{
	REQUIRE(spiral->get_value(2, -1) == 12);
}

TEST_CASE("get size of spiral", "[get_size]")
{
	REQUIRE(spiral->get_size() == 7);

}