#include<iostream>
#include<math.h>
using namespace std;
class polar{
	double r, a;

public:
	polar()
	{
		r = 0;
		a = 0;
	}
	
	polar(double radius, double angle)
	{
		r = radius;
		a = angle;
	}
	
	double getx()
	{
		double val;
		val = a * 3.14 / 180;
		return (r * cos(val));
	}
	
	double gety()
	{
		double val;
		val = a * 3.14 / 180;
		return (r * sin(val));
	}
	
	void printRect()
	{
		double x , y;
		x = getx();
		y = gety() ;
		
		// cout<<"Polar Coordinates ("<<r<<","<<a<<")";
		cout<<"Rectangular coordinates("<<x<<","<<y<<")";
	}
	
	polar operator+(polar o2)
	{
		polar o3;
		double x , y;
		x = getx() + o2.getx();
		y = gety() + o2.gety();
		o3.r = sqrt(x*x +  y*y);
		o3.a = atan(y/x) * 180 /3.14;
		return o3;
	}	

	void displayData()
	{
		cout<<"("<<r<<","<<a<<")";
	}
};
main()
{
	polar o1(13,22.6), o2(4,5), o3;
	o3=o2+o1;
	
	o1.printRect();
	o1.displayData();
	cout<<endl;
	o2.printRect();
	o2.displayData();
	cout<<endl;
	o3.displayData();
	o3.printRect();
}