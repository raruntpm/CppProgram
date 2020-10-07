#include<iostream>
#include "Money.h"
#include "DecimalPrecision.h"
using namespace std;

double Money::getMoney()
{
	double temp;
	temp = (double)cents/100;
	temp += dollars;
	return temp;
}

void Money::setMoney(double value)
{
	IntDecimalSplit<unsigned long, unsigned short> (value, 2, &dollars, &cents);
}

Money::Money(unsigned long dol=0, unsigned short cent=0)
{
	dollars = dol;
	cents = cent;
}

Money::Money(double amount)
{
	setMoney(amount);
}

//Copy Constructor
Money::Money(Money& mon)
{
	dollars = mon.dollars;
	cents = mon.cents;
}

bool Money::operator<(Money& mon)
{
	if(getMoney() < mon.getMoney())
		return 1;
	else
		return 0;
}

bool Money::operator==(Money& mon)
{
	if(getMoney() == mon.getMoney())
		return 1;
	else
		return 0;
}

Money Money::operator+(Money& mon)
{
	Money mon1;
	double temp;
	temp = getMoney() + mon.getMoney();
	mon1.setMoney(temp);
	return mon1;
}

//Subtraction operator overloading
Money Money::operator-(Money& mon)
{
	Money mon1;
	double money1, money2;
	money1 = getMoney(); 
	money2 = mon.getMoney(); 
	if(money1<money2)
	{
		cout<<"you are subtracting the smaller number from the larger number\n";
		mon1.dollars = 0;
		mon1.cents = 0;
	}
	else
	{
		money1 = money1 - money2;
		mon1.setMoney(money1);
	}
	return mon1;
}

//Multiplication overloading
Money Money::operator*(double val)
{
	Money mon;
	double temp;
	temp = getMoney() * val;
	mon.setMoney(temp);
	return mon;
}

Money &Money::operator+=(Money& mon)
{		
	double temp;
	temp = getMoney() + mon.getMoney();
	setMoney(temp);
	return *this;
}

Money Money::operator+()
{		
	double temp;
	temp = getMoney();
	setMoney(temp);
	return *this;
}

void Money::operator!(void)
{
	cout<<"$"<<dollars<<".";	//<<cents<<endl;
	if(cents<10)
		cout<<"0";
	cout<<cents<<endl;
}