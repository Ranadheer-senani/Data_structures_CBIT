#include<iostream>
using namespace std;
class deque
{
	int* ptr;
	int front;
	int rear;
	int size;
	public:
		deque(int);
		void pushFront(int);
		void pushRear(int);
		void popFront();
		void popRear();
		void display();
		void displayFront();
		void displayRear();
		bool isFull();
		bool isEmpty();
};
deque::deque(int n){
	ptr=new int[n];
	front=-1;
	rear=-1;
	size=n;
}
bool deque::isFull()
{
	if((rear==(size-1)&&front==0)||(rear==front-1))
		return true;
	else
		return false;	
}
bool deque::isEmpty()
{
	if(front==-1&&rear==-1)
		return true;
	else
		return false;	
}
void deque::pushFront(int ele)
{
	if(isFull())
		cout<<"queue is full"<<endl;
	else
	{
		if(front==-1)
		{
			cout<<"cant insert at front if queue is empty"<<endl;
		}
		 else if(front==0)
		{
			front=size-1;
			ptr[front]=ele;
		}
		else
			ptr[--front]=ele;
	}			
}
void deque::pushRear(int ele)
{
	if(isFull())
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
		if(rear==-1)
		{
			front=0;
			ptr[++rear]=ele;
		}
		else if(rear==size-1)
		{
			rear=0;
			ptr[rear]=ele;
		}
		else
		{
			ptr[++rear]=ele;
		}
	}
}
void deque::popFront()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==size-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
}
void deque::popRear()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(rear==0)
		{
			rear=size-1;
		}
		else
		{
			--rear;
		}
	}
}
void deque::displayFront()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		cout<<ptr[front];
	}
}
void deque::displayRear()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		cout<<ptr[rear];
	}
}
void deque::display()
{
	if(isEmpty())
	{
		cout<<"queue is empty"<<endl;
	}
	else
	{
		if(rear>=front)
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<ptr[i]<<endl;
			}
		}
		else
		{
			for(int i=front;i<=size-1;i++)
			{
				cout<<ptr[i]<<endl;
			}
			for(int i=0;i<=rear;i++)
			{
				cout<<ptr[i]<<endl;
			}
		}
	}
}
 main()
 {
 	deque q(3);
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
				q.pushFront(ch);
				break;
			case 2: //To insert an element at rear
				cout<<"\nEnter the element to be inserted\t: ";
				cin>>ch;
				q.pushRear(ch);
				break;	
			case 3: //To delete the top element from the front
				q.popFront();
                break;
            case 4: //To delete the top element from the rear
				q.popRear();
                break;
			case 5://To display the element pointed by front	
				q.displayFront();
				break;
			case 6: //To display the element pointed by rear
				q.displayRear();
				break;
			case 7:// To display the elements of the queue
				q.display();
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
