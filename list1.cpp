//Single Linked List ADT
#include<iostream> 
using namespace std;
class list;//forward Declaration 
class node
{
friend class list; 
private:
int data; //data part
node *link; //link part
};
class list
{
private:
node *head; 

public:
list()
{
head=NULL;

}
void create();//To create a list with n nodes
 void insEnd();//To insert a node at end 
 void insFront();//To insert a node at front
void insPos(int);//To insert a node at specified position 
void delEnd();//To delete last node
void delEle(int);//To delete a node with specified element
void delFront();//To delete first node
void dispList();//To display list
int countEle();//To count no. of nodes in list
int getNthNode(int);
};
void list::create()
{

		node* t=new node;
		cout<<"enter the element"<<endl;
		cin>>t->data;
		t->link=NULL;
		if(head==NULL)
		{
		head=t;
		}
		else
		{
			node* n=head;	
			while(n->link!=NULL)
			{
				n=n->link;
			}
			n->link=t;
		}
}
void list::dispList()
{
	if(head==NULL)
	{
		cout<<"the array is empty"<<endl;	
	}
	else{
		node* n= head;
		while(n!=NULL)
		{
			cout<<n->data<<endl;
			n=n->link;
		}	
	}
}
void list::insEnd()
{
	node* t=new node;
	cout<<"enter the element"<<endl;
	cin>>t->data;
	t->link=NULL;
	if(head==NULL){
		head=t;
	}
	else
	{
		node* t1=head;
		while(t1->link!=NULL)
		{
			t1=t1->link;
		}
		t1->link=t;
	}
}
void list::insFront()
{	
	node* t=new node;
	cout<<"enter the integer element"<<endl;
	cin>>t->data;
	t->link=NULL;
	if(head!=NULL)
	{
			t->link=head;
	}
		head=t;
	
}
int list::countEle()
{
	int count=0;
	if(head!=NULL)
	{
		node* t=head;
		while(t!=NULL)
		{
			count++;
			t=t->link;
		}
	}
		return count;
}
void list::insPos(int pos)
{

	if(pos>countEle()||pos<1)
	{
		cout<<"invalid position"<<endl;
	}
	else
	{
		node* t=new node;
		cout<<"enter integer element"<<endl;
		cin>>t->data;
		t->link=NULL;
		node* t1=head;	
		for(int i=2;i<pos;i++)
		{
			t1=t1->link;
		}
		 if(pos==1)
		{
			head=t;
			t->link=t1;
			
		}
		else
		{
			t->link=t1->link;
			t1->link=t;	
		}
	}
}
void list::delEnd()
{
	if(head==NULL)
	{
		cout<<"SLL is empty"<<endl;
		
	}
	else if(head->link==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{
		node* t=head;
		while(t->link->link!=NULL)
		{
			t=t->link;
		}
		delete t->link;
		t->link=NULL;
	}
}
void list::delFront(){
	if(head==NULL)
	{
		cout<<"SLL is underflow"<<endl;
	}
	else
	{
		node* t=head;
		head=t->link;
		delete t;
	}
}
void list::delEle(int ele)
{
	node* t=head;
	if((head->data)==ele)
	{
		head=head->link;
		delete t;	
	}
	else
	{
		while(t->link->data!=ele)
		{
			if(t->link->link==NULL)
			{
				
				break;
			}
			else
			{
				t=t->link;
			}
		}
		if(t->link->link==NULL)
			{
				cout<<"Element is not found"<<endl;
			}
			else{
					node* t1=t->link;
				t->link=t->link->link;
				delete t1;
			}
	
	}
}
int list::getNthNode(int n)
{
	static node* t=head;
	if(t == NULL)
       {
           return 1;
       }
       t=t->link;
       int cur=getNthNode(n);
       if(cur == n)
       {
           return (t->data);
       }
       else if(head==t)
       {
           return -1;
       }
       else {
           return (++cur);
       }
}
main()
{
	int n;
	cout<<"enter the number of elements needed to be added"<<endl;
	cin>>n;
	list l;
	for(int i=0;i<n;i++)
	{
		l.create();
	}
	 cout<<l.getNthNode(3);
}
