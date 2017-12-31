#pragma once
#include <string>
#include <unordered_map>
#include <utility>

namespace aoc
{
	class Memory
	{
		public:
			Memory();
			int get(const std::string& name);
			void set(const std::string& name, int value);
			std::pair<std::string, int> max_element();
			int get_ever_max_value();

		private:
			bool is_in_container(const std::string& name);
			void set_ever_max_value(int value);

			std::unordered_map<std::string, int> container;
			int ever_max_value;
	};
}