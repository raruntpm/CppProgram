#include<iostream>
using namespace std;

template <class T>
T sum(T a, T b)
{
	T c;
	c = a + b;
	            return c;
}

int main(){
	int a = 5, b = 3, c;
	double f = 3.2, g = 2.3, h;
	c = sum<int>(a,b);
	h = sum<double>(f,g);
	cout<<"int sum "<< c << endl;
	cout<<"double sum "<< h <<endl;
}
