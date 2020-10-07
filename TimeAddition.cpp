#include<iostream>
using namespace std;
class Time {
	int hr, min, sec;
public:
	Time()
	{
		hr = 0;
		min = 0;
		sec = 0;
	}
	
	Time(int a, int b, int c)
	{
		hr = a;
		min = b;
		sec = c;
	}
	
	Time addTime(Time t1, Time t2)
	{
		Time t3;
		t3.sec = t1.sec + t2.sec;
		if(t3.sec > 60)
		{
			t2.min += 1;
			t3.sec -= 60;
		}
		t3.min = t1.min + t2.min;
		if(t3.min >60)
		{
			t2.hr += 1;
			t3.min -= 60;
		}
		t3.hr = t1.hr + t2.hr;
		// t3.hr = t3.hr % 24;
		return t3;
	}
	
	void displayTime()
	{
		if(hr<10)
		{
			cout<<"0"<<hr;
		}
		else
		{
			cout<<hr;
		}
		if(min < 10)
		{
			cout<<":0"<<min;
		}
		else
		{
			cout<<":"<<min;
		}
		if(sec < 10)
		{
			cout<<":0"<<sec;
		}
		else
		{
			cout<<":"<<sec<<endl;
		}	
	}
	
};
main()
{
	Time t1(0, 20, 23), t2(0, 23,23), t3;
	t3 = t3.addTime(t1, t2);
	t3.displayTime();
}