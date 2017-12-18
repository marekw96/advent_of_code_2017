#pragma once

#include <string>
#include <vector>

namespace day7
{
	struct node;

	struct node_ptr
	{
		std::string name;
		node* ptr;
	};

	struct node
	{
		std::string name;
		int value;
		std::vector<node_ptr> nodes;
		node* parent;

		node();

		static node from_line(const std::string& line);
		enum class PARSE_STATE{NAME,VALUE,CHILDREN};
	};

	std::vector<node> lines_to_nodes(const std::vector<std::string>& lines);
	void set_parents(std::vector<day7::node>& nodes);
	std::vector<node>::iterator find(std::vector<day7::node>& list, const std::string& name);
	void sum_tower(std::vector<day7::node>& nodes);
}