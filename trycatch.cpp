#include <iostream>
using namespace std;

int main(){
	double a, b;
	try{		
		cout<<"Enter the Dividend --> ";
		if(!(cin>>a))
		{
			throw "Wrong Data type";
		}
		cout<<"Enter the Divisor --> ";
		if(!(cin>>b))
		{
			throw "wrong Data type";
		}
		if(b==0)
		{
			throw "Divide by zero exception";
			// throw 0;
		}
		cout<<"The quotient is "<<a/b;
	}
	catch(const int e){
		cout<<"Error number -> "<<e;
	}
	catch(const char* msg){
		cerr<< "Error : "<<msg;
	}
	catch(...){
		cout<<"Unknwon exception";
	}
	
}