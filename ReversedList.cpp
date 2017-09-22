/*
Program the creates a linked list then uses a function to inverse the
* list order
* By: Andrew Whitehurst
*/
#include <iostream>

using namespace std;

struct node{
	int data;
	node * next;
};

node *newNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->next = nullptr;
	
	return newNode;
}

node *createList(){
	node *first = nullptr, *last = nullptr; // To keep track of the first and the last node
	node *temp = nullptr; // temp node to create and add a new node into the list
	
	temp = newNode(0);
	first = temp;
	last = temp;
	
	for(int i = 1; i < 11; i++){
		temp = newNode(i);
		last->next = temp;
		last = temp;
	}
	
	return first;
}

void forwardPrint(node *current){
	if (current != nullptr){
		cout << current->data << " ";
		forwardPrint(current->next);
	}
}

// Recursively print linkedList in reverse order
void reversePrint(node *current){
	if (current != nullptr){
		reversePrint(current->next); // print the tail
		cout << current->data << " "; // print the node
	}
}


int main(){
	
	node *myList = createList();
	
	cout << "List is: "; 
	forwardPrint(myList); 
	cout << endl;
	cout << "List reverse is: ";
	reversePrint(myList);
	cout << endl;
	
	cin.get();
	cin.get();
	
	return 0;
	
}
