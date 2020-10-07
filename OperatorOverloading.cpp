#include<iostream>
#include<string.h>
using namespace std;

class employee{
	string name;
	int empno;
	float salary;
	
public:
	string name1()  { return name; }
	int empno1()    { return empno; }
	float salary1() { return salary; }
	
	void setName(string Name) {
		
		name = Name;
	}
	void setEmpNo(int Empno) { empno = Empno; }
	void setSalary(float Salary) { salary = Salary; }
	
};

//For cin operation
istream& operator>>(istream& in, employee& emp)
{
	string Name;
	int empno;
	float salary;
	cout << "Enter the Name of Emp";
	in >> Name;
	emp.setName(Name);
	cout << "Enter the EmpNO";
	in >> empno;
	emp.setEmpNo(empno);
	cout << "Enter the salary";
	in >> salary;
	emp.setSalary(salary);
	
}

//For Cout
ostream& operator<<(ostream& out, employee& emp)
{
	return out << "Name : " << emp.name1() << "\nEmp No : " << emp.empno1() 
			   << "\nSalary: " << emp.salary1();
}

int main(){	
	employee emp;
	cin>>emp;
	cout<<emp;
	return 0;
}

