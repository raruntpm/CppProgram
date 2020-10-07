#include<iostream>
using namespace std;
class Distancefeet;		//Forward Declaration
class DistanceMeter{
	float mt;
	int cm;
public:
	friend DistanceMeter addDistance(DistanceMeter d1, Distancefeet d2);
	void getData()
	{
		cout<<"Enter the Distance in Meters and Centimeters";
		cin>>mt>>cm;
	}
	
	void displayData()
	{
		cout<<"The distance is "<<mt<<"m and "<<cm<<"cm";
	}
};

class Distancefeet{
	float ft;
	int inch;
public:
	friend DistanceMeter addDistance(DistanceMeter d1, Distancefeet d2);
	void getData()
	{
		cout<<"Enter the Distance in Feet and Inch";
		cin>>ft>>inch;
	}
	
	void displayData()
	{
		cout<<"The distance is "<<ft<<"feet and "<<inch<<"inch";
	}
};

DistanceMeter addDistance(DistanceMeter d1, Distancefeet d2)
{
	DistanceMeter d3;
	d3.cm = d1.cm + ( d2.ft * 30 ) + ( d2.inch * 2.54);
	d3.mt = d1.mt + ( d3.cm / 100 );
	d3.cm = d3.cm % 100;
	return d3;
}
main()
{
	DistanceMeter d1, d3;
	Distancefeet d2;
	
	d1.getData();
	d2.getData();
	d3 = addDistance(d1, d2);
	d3.displayData();		
}
