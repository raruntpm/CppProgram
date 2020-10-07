#include<iostream>
#include<math.h>
using namespace std;
class Money{
	unsigned long dollars;
	unsigned short cents;

public:

	double combine(unsigned long dol, unsigned short cen){
		double temp;
		temp = (double)cen/100;
		temp += dol;
		return temp;
	}
	
	void split(double value, unsigned long *dol, unsigned short *cen)
	{
		unsigned long amt;
		amt = (unsigned long)(value * 1000);
		*dol = amt / 1000;
		*cen = (amt % 1000)/10;
		if((amt % 10) >= 5)
		{
			*cen += 1;
		}		
	}
	
	Money(unsigned long dol=0, unsigned short cent=0)
	{
		dollars = dol;
		cents = cent;
	}

	Money(double amount)
	{
		split(amount, &dollars, &cents);
	}

	bool operator<(Money& mon)
	{
		if(dollars < mon.dollars)
		{
			if(cents < mon.cents)
			return 1;
		}
		else
		return 0;
	}

	bool operator==(Money& mon)
	{
		if(mon.dollars == dollars){
			if(mon.cents == cents)
			return 1;
		}
		else
		return 0;
	}

	Money operator+(Money& mon)
	{
		Money mon1;
		mon1.cents = mon.cents + cents;
		if(mon1.cents >= 100)
		{
			mon1.cents -= 100;
			mon1.dollars = dollars + mon.dollars + 1;
		}
		else
			mon1.dollars = dollars + mon.dollars;
		return mon1;
	}

	//Subtraction operator overloading
	Money operator-(Money& mon)
	{
		Money mon1;
		double money1, money2;
		money1 = combine(dollars, cents);
		money2 = combine(mon.dollars, mon.cents);
		cout<<money1<<" "<<money2<<endl;
		if(money1<money2)
		{
			cout<<"you are subtracting the smaller number from the larger number\n";
			mon1.dollars = 0;
			mon1.cents = 0;
		}
		else
		{
			money1 = money1 - money2;
			cout<<money1<<endl;
			split(money1, &mon1.dollars, &mon1.cents);
		}
		return mon1;
	}
	
	
	
	//Multiplication overloading
	Money operator*(double val)
	{
		Money mon;
		double temp;
		temp = combine(dollars, cents) * val;
		split(temp, &mon.dollars, &mon.cents);
		return mon;
	}
	
	Money operator+=(Money& mon)
	{		
		cents = mon.cents + cents;
		if(cents >= 100)
		{
			dollars += 1;
			cents -= 100;
		}
		dollars = dollars + mon.dollars;
		return *this;
	}

	Money operator+()
	{		
		int num;
		if(cents > 100)
		{
			num = cents / 100;
			cents = cents % 100;
			dollars = num + dollars;
		}
		return *this;
	}
	void operator!(void)
	{
		cout<<"$"<<dollars<<".";	//<<cents<<endl;
		if(cents == 0)
		cout<<"00"<<endl;
		else if(cents<10)
		cout<<"0"<<cents<<endl;
		else
		cout<<cents<<endl;
	}


	void printMoney()
	{
		cout<<"$"<<dollars<<"."<<cents<<endl;
	}
}; 

int main(){
	Money mon1(7.564);
	Money mon2(5.677);
	Money mon3(0.00);
	Money mon4(5, 150);

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
	
	//Unary operator plus
	cout<<"\nReducing money using unary +\n";
	+mon4;
	!mon4;
	
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
	mon3 = mon1 + mon2;
	!mon3;
	
	//Multiplication by double argument
	cout<<"\n Multiplication of Money1 with 1.1\t ";
	mon3 = mon1 * 1.1;
	!mon3;
	
	// += operator overloading
	cout<<"Adding the Money1 with Money3\t ";
	mon3 += mon1;
	!mon3;	
}
