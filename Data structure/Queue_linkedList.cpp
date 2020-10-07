#include<iostream>
using namespace std;

struct node{
	int info;
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
	void reverse();
	void reverseprint(T *);
};

template <class T>
T *linkedList<T>::getHead()
{
	return head;
}

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
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void linkedList<T>::insertBegin(T *value)
{
	T *temp;
	temp = value;	
	if(isEmpty())
	{
		temp->next = NULL;
		head = tail = temp;
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
	if(isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
		
}

template <class T>
void linkedList<T>::deleteBegin()
{
	T *temp;
	if(isEmpty())
	{
		cout<<"\nThe list is empty\n\n";
		return;
	}
	else if(head->next == NULL)	//only one element in list
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
		cout<<"\nThe list is empty\n\n";
		return;
	}	
	else if(head->next == NULL)
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
		cout<<"\nThe list is empty\n\n";
		return;
	}
	cout<<"\nThe value in the list are\n";
	while(temp != NULL)
	{
		cout<<temp->info<<" ";
		temp = temp->next;
	}
	cout<<endl<<endl;
}

//The following function reverse the order of linked list
template <class T>
void linkedList<T>::reverse()
{
	T *current, *previous;
	current = head;
	previous = 0;
	while(current)
	{
		T *r = previous;
		previous = current;
		current = current->next;
		previous->next = r;
	}
	head = previous;
}

//Reverse print the list
template <class T>
void linkedList<T>::reverseprint(T *val)
{
	if(val == NULL)
	{
		return;
	}
	reverseprint(val->next);
	cout<<val->info<<" ";
}

int main(){
	linkedList<struct node> queue;
		struct node *temp;
	while(1)
	{
		int choice, value;
		cout<<"Enter the choice\n";
		cout<<"1.Enqueue \n2.Dequeue \n3.Display \n4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:  cout<<"Enter the value to be Enqueued\n";
				temp = new(struct node);
				cin>>temp->info;
				queue.insertBegin(temp);
				break;
			case 2: queue.deleteLast();
					break;
			case 3: queue.display();
				break;
			case 4: return 1;
				break;			
			default: break;
		}
	}

	return 0;
}	