// Used to explain the copy constructor

#include<iostream>
using namespace std;

class Example{
	int x, y;
public:
	Example(int a, int b)
	{
		x = a;
		y = b;
	}
	
	void display()
	{
		cout<<x << y;
	}
};
int main()
{
	Example obj1(2,3);
	Example obj2= obj1;
	
	cout<<"Obj 1 is "; obj1.display();
	cout<<"Obj 2 is "; obj2.display();
}
