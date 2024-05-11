#include "Graph.h"
#include <conio.h>

bool Graph::CheckExistence(int value)
{
	for (auto m : graph)
		if (m->value == value)
			return true;

	return false;
}

Node* Graph::Search(int value)
{
	for (auto n : graph)
		if (n->value == value)
			return n;
	
	return nullptr;
}

Graph::Graph()
{
}

Graph::~Graph()
{
	graph.clear();
}

void Graph::ConsolePrint()
{
	for(auto n : graph)
	{
		std::cout << n->value << ": ";
		for (auto m : n->edges)
			std::cout << m << ", ";
		std::cout << "\b\b  \n";
	}
}

void Graph::Task()
{
	int count = 0;

	for (auto n : graph)
	{
		for (auto m : friendlyNumbers)
		{
			if (m[0] == n->value)
			{
				for (auto l : n->edges)
					if (l == m[1])
						count++;
			}
		}
	}

	std::cout << "Count the number of pairs of friendly number: " << count << std::endl;
}

void Graph::AddNode()
{
	int tmp = 0;
	bool flag = true;

	while (flag)
	{
		std::cout << "Enter node value: ";
		std::cin >> tmp;

		if (CheckExistence(tmp))
		{
			std::cout << "Such node already exists!" << std::endl;
			continue;
		}

		graph.push_back(new Node(tmp));

		std::cout << "Specify the connections." << std::endl;
		while (true)
		{
			std::cout << "Enter connection(n < 0 for exit): ";
			std::cin >> tmp;

			if (tmp < 0)
				break;

			if (CheckExistence(tmp))
			{
				int tmp1 = 1;
				for(auto n : graph.back()->edges)
					if(n == tmp)
					{
						std::cout << "Such connection already exists!" << std::endl;
						tmp1 = 0;
						break;
					}
				if (tmp1 == 0)
					continue;

				if(tmp != graph.back()->value)
				{
					graph.back()->edges.push_back(tmp);
					Search(tmp)->edges.push_back(graph.back()->value);
				}
				else
					graph.back()->edges.push_back(tmp);
			}
			else
				std::cout << "There is no such node!" << std::endl;
		}

		flag = false;
	}
}
