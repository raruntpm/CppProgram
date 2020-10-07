#ifndef __MONEY__H__
#define __MONEY__H__

class Money{
private:
	unsigned long dollars;
	// unsigned long cents;
	unsigned short cents;
public:
	Money(unsigned long dol, unsigned short cent);
	Money(double amount);	
	Money(Money& mon);	//Copy Constructor
	double getMoney();
	void setMoney(double);
	bool operator<(Money& mon);
	bool operator==(Money& mon);
	Money operator+(Money& mon);
	Money operator-(Money& mon);
	Money operator*(double val);
	Money &operator+=(Money& mon);
	Money operator+();
	void operator!(void);
};

#endif