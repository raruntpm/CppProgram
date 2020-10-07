#include<iostream>
using namespace std;

class person{
	string name;
	int age;
public:

	person(){
		cout<<"In class person constructor"<<endl;
	}
	
	void setName(string Name){
		name = Name;
	}
	
	string getName()
	{
		return name;
	}
	
	void setAge(int Age){
		age  = Age;
	}
	
	int getAge(){
		return age;
	}
	
	~person(){
		cout<<"In person class destructor"<<endl;
	}
};

// class physique: public person{
class physique: virtual public person{
	float height, weight;
public:

	physique(){
		cout<<"In Class physique constructor"<<endl;
	}
	void setHeight(float ht){
		height = ht;
	}
	float getHeight(){
		return height;
	}
	void setWeight(float wt){
		weight = wt;
	}
	float getWeight(){
		return weight;
	}
	~physique(){
		cout<<"In physique class destructor"<<endl;
	}
};

// class family: public person{
class family: virtual public person{
	int numChildren;
	string religion;
public:
	family(){
		cout<<"In class family constructor"<<endl;
	}
	
	void setNumChildren(int child){
		numChildren = child;
	}
	int getNumChildren(){
		return numChildren;
	}
	void setReligion(string rel){
		religion = rel;
	}
	string getReligion(){
		return religion;
	}
	~family(){
		cout<<"In family class destructor"<<endl;
	}
};

class employee:public physique, public family{
	int empno;
	float salary;
public:
	employee(){
		cout<<"In class employee constructor"<<endl;
	}
	void setEmpNo(int Empno){
		empno = Empno;
	}
	int getEmpNo(){
		return empno;
	}
	void setSalary(float Salary){
		salary = Salary;
	}
	float getSalary(){
		return salary;
	}	
	~employee(){
		cout<<"In employee class  Destructor"<<endl;
	}
};

int main(){
	// person per;
	// physique phy;
	// family fam;
	
	cout<<"\nCreation of emp object"<<endl;
	employee emp;
	
	
	emp.setName("Arun");
	emp.setAge(26);
	emp.setHeight(6.6);
	emp.setWeight(70);
	emp.setNumChildren(0);
	emp.setReligion("Hindu");
	
	cout<<"\nEmployee Details"<<endl;
	cout<<"Name is "<<emp.getName()<<endl;
	cout<<"Age is "<<emp.getAge()<<endl;
	cout<<"Height is "<<emp.getHeight()<<endl;
	cout<<"weight is "<<emp.getWeight()<<endl;
	cout<<"No of childern is "<<emp.getNumChildren()<<endl;
	cout<<"Religion is "<<emp.getReligion()<<endl;
	
	cout<<"\nSize of the class"<<endl;
	// cout<<"size of Person class "<<sizeof(per)<<endl;
	// cout<<"size of physique class "<<sizeof(phy)<<endl;
	// cout<<"size of family class "<<sizeof(fam)<<endl;
	cout<<"size of employee class "<<sizeof(emp)<<endl<<endl;
	
}