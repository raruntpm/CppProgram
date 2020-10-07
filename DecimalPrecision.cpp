#include <iostream>
using namespace std;

// void IntDecimalSplit(double value, int n, unsigned int *intPart,
				     // unsigned int *decPart){
	// unsigned int temp;
	// int i, precision = 1;
	
	// *intPart = (unsigned int) value;	//Extract the Integer Part
	// // Power Function
	// for(i=0; i < n; i++)
	// {
		// precision = 10 * precision;
	// }
	
	// temp  = value * precision * 10;
	// *decPart = (temp % ( precision * 10 ) ) / 10;
	// if(( temp % 10) >= 5)
	// {
		// *decPart += 1;
		// if(*decPart == precision)
		// {
			// *intPart += 1;
			// *decPart = 0;
		// }
	// }
// }

template <class T>
void IntDecimalSplit(double value, int n, T *intPart,
				     T *decPart){
	T temp;
	int i, precision = 1;
	
	*intPart = (unsigned int) value;	//Extract the Integer Part
	//Power Function
	for(i=0; i < n; i++)
	{
		precision = 10 * precision;
	}
	
	temp  = value * precision * 10;
	*decPart = (temp % ( precision * 10 ) ) / 10;
	if(( temp % 10) >= 5)
	{
		*decPart += 1;
		if(*decPart == precision)
		{
			*intPart += 1;
			*decPart = 0;
		}
	}
}

void convert(float val)
{
	unsigned int Integer, Decimal;
	IntDecimalSplit(val, 2, &Integer, &Decimal);
	cout<< Integer << " "<< Decimal<<endl;
}

int main(){
	convert(5.556);
	convert(1.999);
	convert(5.445);
	return 0;
}