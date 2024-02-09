#include "DoublyLinkedList.h"
#include"Node.h"
#include<iostream>
#include<string>
using namespace std;
DoublyLinkedList::DoublyLinkedList()
{
	first = 0;
	last = 0;
}
void DoublyLinkedList::insertAtEnd(string data1)
{
	Node* temp;
	temp = new Node();
	temp->data = data1;
	temp->next = 0;
	temp->prev = 0;
	if (first == 0)
	{
		// empty list
		first = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
	cout << "Data is inserted successfully!!" << endl;
}
void DoublyLinkedList::insertAtStart(string data2)
{
	Node* temp;
	temp = new Node;
	temp->data = data2;
	temp->prev = 0;
	temp->next = 0;
	if (first == 0)
	{
		// empty list
		first = temp;
		last = temp;
	}
	else
	{
		temp->next = first;
		first->prev = temp;
		first = temp;
	}
	cout << "Data inserted successfully!!" << endl;
}
void DoublyLinkedList::insertItem(string data3)
{
	Node* temp = new Node();
	temp->data = data3;
	temp->prev = nullptr;
	temp->next = nullptr;

	if (first == nullptr)
	{
		// empty list
		first = temp;
		last = temp;
	}
	else if (data3 <= first->data)
	{
		// insert at beginning
		temp->next = first;
		first->prev = temp;
		first = temp;
	}
	else if (data3 >= last->data)
	{
		// insert at end
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
	else
	{
		// insert in middle
		Node* current = first->next;
		while (current != nullptr)
		{
			if (data3 <= current->data)
			{
				temp->prev = current->prev;
				temp->next = current;
				current->prev->next = temp;
				current->prev = temp;
				break;
			}
			current = current->next;
		}
	}
	cout << "Value Inserted Successfully!!" << endl;
}

void DoublyLinkedList::displayAllItems()
{
	Node* temp = first;
	if (first == 0)
		cout << "Sorry! list is empty" << endl;
	else
	{
		while (temp != 0)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}
void DoublyLinkedList::displayReverse()
{
	if (first == 0)
		cout << "List is empty!!" << endl;
	else
	{
		Node* temp = last;
		while (temp != 0)
		{
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
}
void DoublyLinkedList::displayValues(char value)
{
	if (first == 0)
		cout << "List is empty!!" << endl;
	else
	{
		Node* temp = first;
		while (temp != 0)
		{
			if (temp->data[0] == value)
				cout << temp->data << endl;
			temp = temp->next;
		}
	}
}
unsigned int DoublyLinkedList::CountNodes()
{
	if (first == 0)
		cout << "List is empty!!" << endl;
	else
	{
		unsigned int count = 0;
		Node* temp = first;
		while (temp != 0)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}
void DoublyLinkedList::DeleteFirstNode()
{
	Node* temp = first;
	if (first == 0)
		cout << "Sorry! List is empty!!" << endl;
	else
	{
		first = temp->next;
		first->prev = 0;
		delete temp;
		if (first == 0)
			last = 0;
		cout << "Node deleted successfully!!" << endl;
	}
}
void DoublyLinkedList::DeleteLastNode()
{
	if (first == 0)
		cout << "Sorry! List is empty!!" << endl;
	else if (first == last)
	{
		delete first;
		first = 0;
		last = 0;
		cout << "Node deleted successfully!!" << endl;
	}
	else
	{
		Node* temp = first;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		last = last->prev;
		delete temp;
		last->next = 0;
		cout << "Node deleted successfully!!" << endl;
	}
}
void DoublyLinkedList::DeleteItem(string value)
{
	Node* temp = first;
	bool found = false;
	if (first == 0)
		cout << "Sorry! List is empty!!" << endl;
	else
	{
		while (temp != 0 && found == false)
		{
			if (temp->data == value)
				found = true;
			else
				temp = temp->next;
		}
		if (found == false)
			cout << "Value did'nt found in the list!!" << endl;
		else
		{
			if (temp == first)
				DeleteFirstNode();
			else if (temp == last)
				DeleteLastNode();
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
			}
			cout << "Value deleted successfully!!" << endl;
		}
	}
}
bool DoublyLinkedList::Find()
{
	bool found = false;
	Node* temp = first;
	string value;
	cout << "Enter the value which you want to find in the list: " << endl;
	cin.ignore();
	getline(cin, value);
	cin.ignore();
	if (first == 0)
		cout << "Sorry! List is empty!!" << endl;
	else
	{
		while (temp != 0 && found == false)
		{
			if (temp->data == value)
			{
				found = true;
				cout << "Value found!!" << endl;
				cout << temp->data << endl;
				return true;
			}
			temp = temp->next;
		}
		if (found == false)
			cout << "Value did'nt found!!" << endl;
		return false;
	}
}
string DoublyLinkedList::FindMinimum()
{
	Node* temp = first;
	string min;
	if (first == 0)
		cout << "Sorry! List is empty!!" << endl;
	else
	{
		min = first->data;
		while (temp != 0)
		{
			if (temp->data < min)
				min = temp->data;
			temp = temp->next;
		}
	}
	return min;
}
DoublyLinkedList::~DoublyLinkedList()
{
	Node* temp = first;
	while (temp != 0)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = 0;
	cout << "List is deleted successfully!!" << endl;
}
