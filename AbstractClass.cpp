#include<iostream>
using namespace std;

/*
* Pure virtual is declared with keyword virtual and it is assigned to
* to zero.
*/
class shape{
	public:
	virtual float area() = 0;
};

/*
* Class rectangle inherits the class shape. Since it inherits the abstract
* it has to define the pure virtual function. If it is not defined, 
* again this class will become abstract class.
*/
class rectangle: public shape{
	int length, breadth;
public:
	void setup(int len, int bd)
	{
		length = len;
		breadth = bd;
	}
	
	float area()
	{
		return length * breadth;
	}

};

class circle: public shape{
	int radius;
public:
	void setup(int rad)
	{
		radius = rad;
	}
	
	float area()
	{
		return ( 3.14 * radius * radius);
	}
};

class triangle: public shape{
	int length, height;
public:
	void setup(int len, int ht)
	{
		length = len;
		height = ht;
	}
	
	float area()
	{
		return ( length * height / 2);
	}
};

//To demonstrate the class which doesn't define the pure virtual function
class dummy: public shape{

public:
	void print(){
		cout<<"Dummy class";
	}
};

int main()
{
	shape *obj1, *obj2, *obj3;
	rectangle rect;
	circle cir;
	triangle tri;
	
	/*
	 * Creating the object for abstract class
	 * When the below statement is executed, the compiler will throw
	 * the error.Since the object for abstract class cannot be created.
	 **/
	// shape obj4;

	/*
	* Dummy Class didn't declare the pure virtual function. Hence it is
	* acts as Abstract class only. So the object cannot be created for 
	* it.
	*/
	// dummy dum;
	
	//Assigning the pointer
	obj1 = &rect;
	obj2 = &cir;
	obj3 = &tri;
	
	//Setting up the values
	rect.setup(2, 4);
	cir.setup(5);
	tri.setup(2, 3);
	
	//Calculate the area by using the base class pointer
	cout<<"area of rect is "<<obj1->area()<<endl;
	cout<<"area of circle is "<<obj2->area()<<endl;
	cout<<"area of triangle is "<<obj3->area()<<endl;	
}

