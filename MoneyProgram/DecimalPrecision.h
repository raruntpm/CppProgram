#ifndef __DECIMAL_PRECISION_H__
#define __DECIMAL_PRECISION_H__

template <class T, class T1>
void IntDecimalSplit(double value, int n, T *intPart,
				     T1 *decPart){
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
#endif