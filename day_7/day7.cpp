#include "day7.h"
#include <sstream>
#include <cctype>
#include <algorithm>

day7::node::node() : name{}, value{0}, nodes(), parent{nullptr}
{}

day7::node day7::node::from_line(const std::string& line)
{
	node temp;
	PARSE_STATE state = PARSE_STATE::NAME;

	auto pos = 0u;
	auto size = line.size();
	std::stringstream holder;
	char letter;

	while (pos != size)
	{
		letter = line[pos++];

		if(!std::isalnum(letter))
		{
			if (holder.str().size())
			{
				if (state == PARSE_STATE::NAME)
				{
					temp.name = holder.str();
					holder.str(std::string());
					state = PARSE_STATE::VALUE;
				}
				else if (state == PARSE_STATE::VALUE)
				{
					temp.value = std::stoi(holder.str());
					holder.str(std::string());
					state = PARSE_STATE::CHILDREN;
				}
				else if (state == PARSE_STATE::CHILDREN)
				{
					node_ptr temp_node_ptr;
					temp_node_ptr.name = holder.str();
					holder.str(std::string());
					temp.nodes.push_back(temp_node_ptr);
				}
			}
			continue;
		}

		holder << letter;
	}

	if (holder.str().size())
	{
		node_ptr temp_node_ptr;
		temp_node_ptr.name = holder.str();
		holder.str(std::string());
		temp.nodes.push_back(temp_node_ptr);
	}

	return temp;
}

std::vector<day7::node> day7::lines_to_nodes(const std::vector<std::string>& lines)
{
	std::vector<day7::node> nodes;
	nodes.reserve(lines.size());

	for(const auto& line : lines)
		nodes.emplace_back(day7::node::from_line(line));

	return nodes;
}

void day7::set_parents(std::vector<day7::node>& nodes)
{
	for (auto& node : nodes)
	{
		for (auto& child : node.nodes)
		{
			auto& found = *day7::find(nodes, child.name);
			found.parent = &node;
			child.ptr = &found;
		}
	}
}

std::vector<day7::node>::iterator day7::find(std::vector<day7::node>& list, const std::string & name)
{
	return std::find_if(std::begin(list), std::end(list),[&name](const auto& item){ return item.name == name;});
}

void day7::sum_tower(std::vector<day7::node>& nodes)
{}
