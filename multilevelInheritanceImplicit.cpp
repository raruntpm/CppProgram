#include<iostream>
using namespace std;

class person{
protected:
	string name;
	int age;
public:

	person(string Name, int Age){
		cout<<"In class person constructor"<<endl;
		name = Name;
		age = Age;
	}
		
	~person(){
		cout<<"In person class destructor"<<endl;
	}
};

class physique: public person
// class physique
{
protected:
	float height, weight;
public:
	physique(string Name, int Age, float Ht, float Wt) : person(Name, Age)
	// physique(float Ht, float Wt)
	{
		cout<<"In Class physique constructor"<<endl;
		height = Ht;
		weight = Wt;
	}
	~physique(){
		cout<<"In physique class destructor"<<endl;
	}
};

class employee:public physique
// class employee:public physique, public person
{
protected:
	int empno;
	float salary;
public:
	employee(string Name, int age, float ht, float wt, int child,
	string rel, int empNo, float Salary)
	: physique(Name, age, ht, wt)
	// : (physique(ht, wt)  , person(Name, age))
	{
		cout<<"In class employee constructor"<<endl;
		empno= empNo;
		salary = Salary;
	}
	
	void printDetails(){
		cout<<"\nEmployee Details"<<endl;
		cout<<"Name is "<<name<<endl;
		cout<<"Age is "<<age<<endl;
		cout<<"Height is "<<height<<endl;
		cout<<"weight is "<<weight<<endl;
		// cout<<"No of childern is "<<numChildren<<endl;
		// cout<<"Religion is "<<religion<<endl;
		cout<<"Emp Id is "<<empno<<endl;
		cout<<"Salary is "<<salary<<endl<<endl;
	}
	
	~employee(){
		cout<<"In employee class  Destructor"<<endl;
	}
};

int main(){
	cout<<"\nCreation of emp object"<<endl;
	employee emp("Arun" , 26, 6.6, 70, 0, "Hindu", 6213, 30000);
	emp.printDetails();	
}