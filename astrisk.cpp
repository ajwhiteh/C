#include <iostream>

using namespace std;

void astrisk(int x){
	if(x!=0){
		cout << "*";
		x = x-1;
		astrisk(x);
	}
}

int main(){
	int x;
	cout << "Enter a number..." << endl;
	cin >> x;

	astrisk(x);

	cin.get();
	cin.get();

	return 0;
}
