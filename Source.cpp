#include "Node.h"
#include "DoublyLinkedList.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{
	DoublyLinkedList list;
	unsigned int choice;
	char choice1;
	string value;
	cout << "1. Insert Node at End" << endl;
	cout << "2. Insert Node at Start" << endl;
	cout << "3. Insert Item" << endl;
	cout << "4. Display all Values" << endl;
	cout << "5. Display Values Having Same First Character" << endl;
	cout << "6. Display Reverse Values" << endl;
	cout << "7. Count Nodes" << endl;
	cout << "8. Find a Value" << endl;
	cout << "9. Find a Minimum Value in the list" << endl;
	cout << "10. Delete First Node" << endl;
	cout << "11. Delete Last Node" << endl;
	cout << "12. Delete any Node" << endl;
	cout << "13. Exit" << endl;
	do
	{
		cout << "Enter your choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the data which you want to insert: " << endl;
			cin.ignore();
			getline(cin, value);
			list.insertAtEnd(value);
			break;
		case 2:
			cout << "Enter the data which you want to insert" << endl;
			cin.ignore();
			getline(cin, value);
			list.insertAtStart(value);
			break;
		case 3:
			cout << "Enter the value which you want to insert: " << endl;
			cin.ignore();
			getline(cin, value);
			list.insertItem(value);
			cin.ignore();
			break;
		case 4:
			cout << "Here is the list of the items!!" << endl;
			list.displayAllItems();
			break;
		case 5:
			char value1;
			cout << "Enter the character: " << endl;
			cin >> value1;
			cout << "Items having same first character!!" << endl;
			list.displayValues(value1);
			break;
		case 6:
			cout << "Here is the list in Reverse Order: " << endl;
			list.displayReverse();
			break;
		case 7:
			cout << "Total Nodes in the list: " << endl;
			cout << list.CountNodes() << endl;
			break;
		case 8:
			list.Find();
			break;
		case 9:
			cout << "Minimum Value in the list" << endl;
			cout << list.FindMinimum() << endl;
			break;
		case 10:
			list.DeleteFirstNode();
			break;
		case 11:
			list.DeleteLastNode();
			break;
		case 12:
			cout << "Enter the value which you want to delete: " << endl;
			cin.ignore();
			getline(cin, value);
			list.DeleteItem(value);
			break;
		case 13:
			exit(0);
			break;
		default:
			cout << "Invalid choice" << endl;
		}
		cout << "Do you again want to enter any choice(Y/N)?" << endl;
		cin >> choice1;

	} while (choice1 == 'y');

	cout << "Program Terminated!!" << endl;

	return 0;
}
