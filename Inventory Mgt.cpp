#include<iostream>
#include<string>
using namespace std;
class book {
	char name[30], author[20];
	float price;
	int count;

public:	
/*
	book()
	{
		strcpy(name, "C Programming");
		strcpy(author, "Dennis Ritchie");
		price = 300.5;
		count = 2;
	}
	*/
	void getInput()
	{
		cout<<"Enter the book name";
		// getline(cin, name);
		getline(name, 30,cin);
		cout<<"Enter the author name";
		getline(cin,author);
		cout<<"Enter the cost of book";
		cin>>price;
		cout<<"Enter the quantity of book";
		cin>>count;	
	}
	
	int searchBook(char title[])
	{
		if(strcmp(name, title) == 0)
		{
			return 1;
		}
		else return 0;
	}
	
	void checkQuantity(int n)
	{
		if(count >= n)
		{
			cout<<"Cost of "<<n<<" books is "<< n* price;	
		}
		else
		{
			cout<<"Request number of quantity not available";
		}
	}
};

int main()
{	
	char title[30];
	int quantity=0, n=0, i=0;
	book obj[5];
	
	cout<<"How many no of books to be Entered\t";
	cin>>n;
	cin.ignore();
	
	cout<<"Enter the Details of each book\n";
	for(i=0; i<n; i++)
	{
		obj[i].getInput();
	}
	
	//Enter the book name to search
	cout<<"Book to search\t";
	getline(cin, title);
	for(i=0; i<n; i++)
	{
		if(obj[i].searchBook(title))
		{
			cout<<"Book found\n"<<"Enter the Number of copies";
			cin>>quantity;
			obj[i].checkQuantity(quantity);
			break;
		}
		else
		{
			cout<<"not found";
		}
	}
}