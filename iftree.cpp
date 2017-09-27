#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node{
	int data;
	node * left;
	node * right;
};

node *newNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->right = nullptr;
	newNode->left = nullptr;
	
	return newNode;
}

node * build_BST(){
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

node * build_not_BST(){
	node *first = nullptr;
	node *end = nullptr;
	node *temp = nullptr;
	
	temp = newNode(0);
	first = temp;
	end = temp;
	
	for(int i = 1; i < 7; i++){
		int randNum;
		srand (time(NULL));
		randNum = rand() % 10 + 1;
		temp = newNode(randNum);
		end->left = temp;
		i++;
		temp = newNode(randNum);
		end->right = temp;
		end = temp;
	}
	return first;
}

//make me work
bool testBST(node * tree){
	if (((tree->left < tree) || (tree->right > tree)) && ((tree->left),(tree->right) != nullptr))
		return false;
	else if (tree->left != nullptr)
		return testBST(tree->left);
	else if (tree->right != nullptr)
		return testBST(tree->right);
	else return true;

}

int main(){
	node * notBST = nullptr;
	node * isBST = nullptr;
	notBST = build_not_BST();
	isBST = build_BST();
	bool statement = false;
	
	statement = testBST(notBST);
	cout << "First tree binary search tree? " << statement << endl;
	statement = testBST(isBST);
	cout << "Second tree binary search tree? " << statement << endl;
	
	cin.get();
	cin.get();
	
	return 0;
}
