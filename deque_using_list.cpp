#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Deque
{
	list<int> l;
	
	public:
		void pushFront(int);
		void pushRear(int);
		void popFront();
		void popRear();
		void display();
		void displayFront();
		void displayRear();
		bool isEmpty();
};
void Deque::pushFront(int ele)
{
	l.push_front(ele);		
}
void Deque::pushRear(int ele)
{
	l.push_back(ele);
}
void Deque::popFront()
{
	if(isEmpty())
		cout<<"queue is empty"<<endl;
	else
		l.pop_front();
}
void  Deque::popRear()
{
	if(isEmpty())
		cout<<"queue is empty"<<endl;
	else	
		l.pop_back();
}
bool Deque::isEmpty()
{
	return l.empty();
}
void Deque::displayFront()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		cout<<l.front()<<endl;
	}
}
void Deque::displayRear()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		cout<<l.back()<<endl;
	}
}
void Deque::display()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
		return;
	}
	list<int>::iterator it;
	for(it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<endl;
	}
}
main()
 {
 	Deque d;
 		int ch,flag=0;
	while(1)
	{
		cout<<"\n\nSTACK OP MENU";
		cout<<"\n 1. Push Front \n 2.Push rear \n 3. Pop Front \n 4.Pop rear \n 5. Display front \n 6.Display back\n 7. Display queue \n 8. Exit\n";
		cout<<"\nEnter your choice\t: ";
		cin  >> ch;
		switch(ch)
		{
			case 1: //To insert an element at front
				cout<<"\nEnter the element to be inserted\t: ";
				cin>>ch;
				d.pushFront(ch);
				break;
			case 2: //To insert an element at rear
				cout<<"\nEnter the element to be inserted\t: ";
				cin>>ch;
				d.pushRear(ch);
				break;	
			case 3: //To delete the top element from the front
				d.popFront();
                break;
            case 4: //To delete the top element from the rear
				d.popRear();
                break;
			case 5://To display the element pointed by front	
				d.displayFront();
				break;
			case 6: //To display the element pointed by rear
				d.displayRear();
				break;
			case 7:// To display the elements of the queue
				d.display();
				break;	
			case 8: //To exit
				cout<<"Bye Bye..";
				_exit(0);
			default:
				cout<<"Only options 1 to 5 are valid. Reenter a valid option";
				break;
		} //End of switch
	}//End of While
 	return 0;
 }
