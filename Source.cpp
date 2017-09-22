/*
Linked List Example
1. Creates dynamic linked list using forward and backward strategies
2. Traverse nodes in the list
3. Insert new node into the list
4. Delete a node from the list
5. Search the list for a given data and return the node with the data
*/

#include <iostream>

using namespace std;

struct nodeType
{
	int info;
	nodeType *link;
};

nodeType *buildListForward()
{
	/*
	// just like using insertEnd method for dyanmic list we created earlier
	// push_back method for vector STL, etc.

	Algorithm steps:
	1. Initialize first and last to nullptr
	2. For each item in the list
	a. Create the new node, newNode
	b. Store the item/data in newNode
	c. Store nullptr to the link of the newNode
	d. Check if the list is empty
	i. If the list is empty:
	a. Make first and last point to newNode
	ii. If the list is not empty
	a. append newNode at the end of the list
	b. update the last node by pointing it to the newNode
	*/
	nodeType *first = nullptr, *last = nullptr; // To keep track of the first and the last node
	nodeType *newNode = nullptr; // temp node to create and add a new node into the list
	int num; // temp var to read data into


	// create temp node with data
	cout << "Enter some numbers ending with -999: ";
	cin >> num;
	while (num != -999)
	{
		newNode = new nodeType;
		newNode->info = num; // store num into info
		newNode->link = nullptr;

		if (first == nullptr) // check if the node is empty
		{   // make the first and last node point to newNode
			first = newNode;
			last = newNode;
		}
		else // list is not empty
		{
			last->link = newNode; // append newNode at the end of the list
			last = newNode; //update the last node by pointing it to the newNode
		}
		cin >> num;
	}
	return first;
}

nodeType *buildListBackward()
{
	/*
	// just like using insertEnd for dyanmic list we created earlier
	// push_front method in list STL, etc.
	Algorithm steps:
	1. Initialize first to nullptr
	2. For each item in the list
	a. Create the new node, newNode
	b. Store the item/data in newNode
	c. Insert newNode before first
	d. Update the value of the pointer first
	*/
	nodeType *first = nullptr; //1
	nodeType *newNode = nullptr; //temp node to create and add a new node into the list
	int num;

	// create temp node with data
	cout << "Enter some numbers ending with -999: ";
	cin >> num;
	while (num != -999)
	{
		newNode = new nodeType; // 2.a.
		newNode->info = num; // 2.b store num into info
		newNode->link = first; // 2.c
		first = newNode; // 2.d update the head pointer of the list
		cin >> num;
	}
	return first;
}

// function to traverse each node starting from head and print the value stored
// in the node
void traverseLinkedList(nodeType *head)
{
	nodeType *currentNode = head;
	while (currentNode != nullptr)
	{
		cout << currentNode->info << " ";
		currentNode = currentNode->link;
	}
	cout << endl;
}

// Recursively print linkedList in reverse order
void reversePrint(nodeType *current)
{
	if (current != nullptr)
	{
		reversePrint(current->link); // print the tail
		cout << current->info << " "; // print the node
	}
	//cout << endl;
}


int main1(int argc, char *argv[])
{
	nodeType *first = nullptr;
	first = buildListForward();
	cout << first->link->info << endl; // print 2nd node's info
	cout << first->link->link->info << endl; // print 3rd node's info

	traverseLinkedList(first);

	// insert a new node in between first and second nodes
	// Let say p points to the first node
	nodeType *p = first;
	// create and initialize new node to add to add
	nodeType *newNode = new nodeType;
	newNode->info = 1000;
	newNode->link = p->link;
	p->link = newNode;
	cout << " After adding node with 1000 into the list:" << endl;
	//reversePrint(first);
	traverseLinkedList(first);

	// delete an existing node
	// Let say p points the node you want to delete
	p = first->link->link->link; // forth node in the link
	//p->link = p->link->link; // remove the node from the list, however
	// this node is dangling, i.e., memory leadk
	nodeType *q = first->link->link;
	q->link = p->link;
	delete p;
	cout << " After deleting  the list:" << endl;
	traverseLinkedList(first);

	traverseLinkedList(first);
	first = buildListBackward();
	traverseLinkedList(first);
	cin.get();
	cin.get();
	return 0;
}