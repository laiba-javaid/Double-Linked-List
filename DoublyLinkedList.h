#pragma once
#include "Node.h"
#include<string>
using namespace std;
class DoublyLinkedList
{
	Node* first;
	Node* last;
public:
	DoublyLinkedList();
	void insertAtEnd(string);
	void insertAtStart(string);
	void insertItem(string);
	void displayAllItems();
	void displayReverse();
	void displayValues(char);
	unsigned int CountNodes();
	void DeleteFirstNode();
	void DeleteLastNode();
	void DeleteItem(string);
	bool Find();
	string FindMinimum();
	~DoublyLinkedList();
};

