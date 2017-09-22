#include <iostream>

using namespace std;

struct node* {
	int value;
	node* next;

};

int addition(node* lst){
	if (lst->value == NULL) return;
	else{
		return lst->value + addition(lst->next);
	}
}

int main(){


	cin.get();
	cin.get();
	
	return 0;
}
