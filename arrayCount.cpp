#include <iostream>
#include <string>

using namespace std;

int letterSearch(string arr,char look){
	if (arr.length()!=0){
		if (arr[arr.length() - 1]==look){
			arr.pop_back();
			return (1 + letterSearch(arr,look));
		}
		else{
			arr.pop_back();
			return (0 + letterSearch(arr,look));
		}
	}
	else return 0;
}

int main(){
	
	string myArray = "  ";
	char look;
	
	cout << "Enter a word or sentence:" << endl;
	cin >> myArray;
	cout << "Enter a letter to look for:" << endl;
	cin >> look;
	
	cout << letterSearch(myArray,look);
	
	cin.get();
	cin.get();
	
	return 0;
}
