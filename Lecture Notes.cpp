
/*
	A linked list is a collection of nodes/elements linked together
	Every node has data and link
	The address of the first node is stored in seperate location called head/first node


	Algorithm to know:
		1. init. first and last to nullptr
		2. for each item in the list
			a. create the new node, newNode
			b.store the item/data in newNode
			c. store nullptr to the link of the newNode
			d. check if the list is empty
				i. if the list is empty:
					a.make first and last point to newNode
				ii. if list is not empty
					a.append newNode at the end of the list
					b.update the last node by pointing it to the newNode

*/


#include <iostream>
#include <vector>

using namespace std;

struct nodeType{
	int data;
	nodeType *link;

};

void traverseLinkedList(nodeType *current){

	while (current != nullptr){
		cout << current->data << endl;
		current = current->link;
	}

}

void printReverse(nodeType *current){
	if (current != nullptr){
		printReverse(current->link);
		cout << current->data << " ";
	}
}

bool search(nodeType *current, int item){
	
	bool found = false;
	
	while (current != nullptr && !found){
		if (current->data == item)
			found = true;
	}
	return found;

}

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
		newNode->data = num; // store num into info
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

int main1(){

	nodeType *head = nullptr, *tail = nullptr; //1, head stores address of what its pointed to, its link shows what the node is linked to
	nodeType *newNode;

	int num = 10;
	newNode = new nodeType;//2.a
	newNode->data = num; //2.b
	newNode->link = nullptr; //2.c

	//2.d
	if (head == nullptr){ //2.d.i
		head = newNode;  //2.d.i.a
		tail = newNode;
	}
	

	//test
	//cout << head << endl;
	//cout << head->link << endl;
	//cout << tail << endl;
	//cout << tail->link << endl;
	//cout << head->data << endl;
	//cout << tail->data << endl;


	//2.d.ii
	num = 5;
	newNode = new nodeType;
	newNode->data = num; 
	newNode->link = nullptr; 
	if (head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->link = newNode; //2.d.ii.a
		tail = newNode; //2.d.ii.b
	}

	//test
	//cout << head << endl;
	//cout << head->link << endl;
	//cout << tail << endl;
	//cout << tail->link << endl;
	//cout << head->data << endl;
	//cout << tail->data << endl;

	system("pause");
	return 0;

}

int main(){

	nodeType *first = buildListForward();



	system("pause");
	return 0;
}