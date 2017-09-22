#include <iostream>
#include <string>

using namespace std;

void question(){
	string x;
	cout << "Do you love me?" << endl;
	cin >> x;
	if(x=="y"||x=="Y"){
		cout << "I love you too!" << endl;
	}
	else{
		question();
	}
}

int main(){
	
	question();
	
	cin.get();
	cin.get();
	
	return 0;
}
