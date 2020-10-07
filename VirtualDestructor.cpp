/*
*	Virtual Destructor is used to Call the destructor of the Derived 
* Class. That is, if we remove the virtual keyword from the base
* destructor, then, if we delete the object, destructor of the 
* derived class will not be executed. In order to execute the derived
* class destructor, you have add virtual keyword to base class destructor
* Compile the code, with and without virtual keyword and you can see
* the difference.
*/

#include<iostream>
using namespace std;
class Base{
public:
	Base(){
		cout<<"In Base class constructor"<<endl;
	}
	
	virtual ~Base(){
		cout<<"In Base class destructor"<<endl;
	}	
};

class Derive:public Base{
	
public:
	Derive(){
		cout<<"In Derive class constructor"<<endl;
	}
	
	~Derive(){
		cout<<"In Derive class Destructor"<<endl;
	}
};

int main(){
	Base *b = new Derive();
	delete b;
}