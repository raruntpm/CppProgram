/* 
*	gcount() - Returns the no of characters extracted by last unformatted
* input operations.
*/
#include<iostream>
using namespace std;

int main(){
	char str[20];
	
	cout<<"Enter the string ";
	cin.getline(str, 20);
	cout<<cin.gcount()<<" characters read "<< str<<endl;
}