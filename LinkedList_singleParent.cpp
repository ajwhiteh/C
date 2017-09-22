/*
Program: Single Parent Binary Tree
By: Andrew Whitehurst

*/

#include <iostream>
#include <string>

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};


node *newNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->right = nullptr;
	newNode->left = nullptr;
	
	return newNode;
}

//I create multiple nodes during the creation of a tree
//so I can have 'holding" points for alternate traversal.
node * buildTree(){
	node *first = nullptr;
	node *end = nullptr;
	node *temp = nullptr;
	
	temp = newNode(0);
	first = temp;
	end = temp;
	
	for(int i = 1; i < 7; i++){
		//cout << "End is at: " << end->data; //test
		temp = newNode(i);
		end->left = temp;
		i++;
		temp = newNode(i);
		end->right = temp;
		end = temp;
		//cout << ". End is going to: " << end->data << endl; //test
	}
	return first;
}

int countSingleParents(node *tree){
	//cout << tree->data << endl; //test
	if((tree->left == nullptr) || (tree->right == nullptr)) return 1;
	return countSingleParents(tree->right) + countSingleParents(tree->left);
}

int main(){

	node *myTree = nullptr;
	myTree = buildTree();
	
	cout << "Number of Parents with 1 or less children is: " << countSingleParents(myTree) << endl;

	cin.get();
	cin.get();
	
	return 0;
}
