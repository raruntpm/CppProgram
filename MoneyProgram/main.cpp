#include <iostream>
#include "money.cpp"
using namespace std;

int main(){
	Money mon1(7.564);
	Money mon2(5.677);
	Money mon3(1.00);
	Money mon4(5, 150);
	Money mon5(mon1);
	Money mon6 = mon2;

	//Overloading ! operator
	cout<<"Printing the value\n";
	cout<<"Money1 = ";
	!mon1;
	cout<<"Money2 = ";
	!mon2;
	cout<<"Money3 = ";
	!mon3;
	cout<<"Money4 = ";
	!mon4;
	cout<<"Money5 = ";
	!mon5;
	cout<<"Money6 = ";
	!mon6;
	
	//Unary operator plus
	cout<<"\nReducing money using unary +\n";
	+mon4;
	!mon4;
	+mon1;
	!mon1;
	
	//Less than operator
	cout<<"\nLess than operator overloading\n";
	if(mon1 < mon2)
		cout<<"money1 is less than money2\n";
	else
		cout<<"money1 is greater than money2\n";

	// comparison operator
	cout<<"\ncomparison operator overloading\n";
	if(mon1 == mon2)
		cout<<"money are equal\n";
	else
		cout<<"money are not equal\n";

	//Addition operator
	cout<<"\nAddition of Money1 and Money2\t";
	mon3 = mon1 + mon2;
	!mon3;
	
	//Subtraction operator
	cout<<"\nSubtraction of Money1 and Money2\t ";
	mon3 = mon1 - mon2;
	!mon3;
	
	//Multiplication by double argument
	cout<<"\n Multiplication of Money1 with 1.1\t ";
	mon3 = mon1 * 1.1;
	!mon3;
	
	// += operator overloading
	cout<<"Adding the Money1 with Money3\t ";
	mon1 += mon2;
	!mon1;		
}