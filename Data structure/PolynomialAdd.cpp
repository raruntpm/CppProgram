#include<iostream>
using namespace std;

struct node{
	int coeff;
	int exp;
	struct node *next;
};

template <class T>
class linkedList{
	T *head;
	T *tail;
	
	bool isEmpty();
public:
	linkedList();
	T *getHead();
	void insertBegin(T *);
	void insertLast(T *);
	void deleteBegin();
	void deleteLast();
	void display();
};

template <class T>
linkedList<T>::linkedList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
bool linkedList<T>::isEmpty()
{
	if(head == NULL && tail == NULL)
	{
		cout<<"\nThe list is empty\n\n";
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
T *linkedList<T>::getHead()
{
	return head;
}
template <class T>
void linkedList<T>::insertBegin(T *value)
{
	T *temp;
	temp = value;	
	if(head == NULL)
	{
		temp->next = NULL;
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}		
}

template <class T>
void linkedList<T>::insertLast(T *value)
{
	T *temp;
	temp = value;
	temp->next = NULL;
	if(tail == NULL)
	{
		head = tail = temp;		
	}
	else
	{
		tail->next = temp;
		tail = temp->next;
	}
	
}

template <class T>
void linkedList<T>::deleteBegin()
{
	T *temp;
	if(isEmpty())
	{
		return;
	}
	else if(head->next == NULL)
	{
		head = tail = NULL;
	}
	else
	{
		temp = head->next;
		head = temp;
	}
}

template <class T>
void linkedList<T>::deleteLast()
{
	T *temp;
	if(isEmpty())
	{
		return;
	}	
	else if(head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		temp = head;
		while(temp->next != tail)
		temp = temp->next;
		tail = temp;
		tail->next = NULL;		
	}
}

template <class T>
void linkedList<T>::display()
{
	T *temp;
	temp = head;
	if(isEmpty())
	{
		return;
	}
	cout<<"\nThe value in the list are\n";
	while(temp->next != NULL)
	{
		cout<<temp->coeff<<"x^"<<temp->exp<<"+";
		temp = temp->next;
	}
	cout<<temp->coeff<<"x^"<<temp->exp;
	cout<<endl;
}


int main()
{
	linkedList<struct node> list;
	linkedList<struct node> list2;
	linkedList<struct node> result;
	struct node *p1, *p2, *p3;
	int contin;
	cout<<"Enter the details of polynomial\n";
	do{
		p1 = new(struct node);
		cout<<"Enter the coefficient";
		cin>>p1->coeff;
		cout<<"Enter the exp";
		cin>>p1->exp;
		list.insertLast(p1);
		cout<<"do you add terms 1=yes 0= no\n";
		cin>>contin;
	}while(contin == 1);
	
	cout<<"Enter the details of second polynomial\n";
	do{
		p1 = new(struct node);
		cout<<"Enter the coefficient";
		cin>>p1->coeff;
		cout<<"Enter the exp";
		cin>>p1->exp;
		list2.insertLast(p1);
		cout<<"do you add terms 1=yes 0= no\n";
		cin>>contin;
	}while(contin == 1);
	
	cout<<"Details of first polynomial";
	list.display();
	cout<<endl;
	cout<<"Details of second polynomial";
	list2.display();
	cout<<endl;
	
	//Addition of two polynomial
	p1 = list.getHead();
	p2 = list2.getHead();
	
	while((p1 != NULL) && (p2 != NULL))
	{
		p3 = new(struct node);
		if(p1->exp == p2->exp)
		{
			p3->coeff = p1->coeff + p2->coeff;
			p3->exp = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1->exp > p2->exp)
		{
			p3->coeff = p1->coeff;
			p3->exp = p1->exp;
			p1 =p1->next;
		}
		else if(p1->exp < p2->exp)
		{
			p3->coeff = p2->coeff;
			p3->exp = p2->exp;
			p2 = p2->next;
		}
		result.insertLast(p3);
	}
	while(p1 != NULL)
	{
		p3 = new(struct node);
		p3->coeff = p1->coeff;
		p3->exp = p1->exp;
		p1 =p1->next;
		result.insertLast(p3);
	}
	while(p2 != NULL)
	{
		p3 = new(struct node);	
		p3->coeff = p2->coeff;
		p3->exp = p2->exp;
		p2 = p2->next;
		result.insertLast(p3);
	}
	cout<<"\nThe addition of two polynomials are \n";
	result.display();
	return 0;
}
