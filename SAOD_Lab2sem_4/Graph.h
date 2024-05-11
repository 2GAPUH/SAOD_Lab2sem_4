#pragma once
#include <vector>
#include <iostream>

const std::vector<std::vector<int>> friendlyNumbers = { {220, 284}, {1184 , 1210}, {2620 , 2924}, {5020 , 5564}, {6232 , 6368}, {10744, 10856} ,{12285 , 14595} 
,{17296 , 18416} ,{63020 , 76084} ,{66928 , 66992} ,{67095 , 71145} ,{69615 , 87633} ,{79750 , 88730}};


/*
5. ¬ вершинах неориентированного графа хран€тс€
положительные целые числа. ѕодсчитайте число пар дружественных
чисел в вершинах графа, которые соединены ребрами.
*/

class Node
{
public:
	int value;
	Node(int value) : value(value) {};
	std::vector<int> edges;
};

class Graph
{
private:
	std::vector<Node*> graph;
	bool CheckExistence(int value);
	Node* Search(int value);

public:
	Graph();
	~Graph();
	void ConsolePrint();
	void Task();
	void AddNode();
};

