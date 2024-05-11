#include <iostream>
#include "Graph.h"


int main()
{
	bool flag = true;
	Graph graph;
	int choice = -1;

	while (flag)
	{
		std::cout << "1 - Add new edge \n2 - Check count the number of pairs of friendly number \n3 - Print graph \n0 - Exit" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			graph.AddNode();
			break;

		case 2:
			graph.Task();
			break;

		case 3:
			graph.ConsolePrint();
			break;

		case 0:
			flag = false;
			break;

		default:
			std::cout << "Invalid value!" << std::endl;
			break;
		}
	}
}