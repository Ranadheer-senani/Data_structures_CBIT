//Program to implement Single Linked List
#include<iostream>
using namespace std;
class list;//forward Declaration
class node
{
	friend class list;
	private:
		int data;	//data part	
		node *link;	//link part
};

class list
{
	private:
		node *head;
	public:
		list(){head=NULL;}
		void create();//To create a list with n nodes
		void insEnd(); //To insert a node at end
		void insFront();//To insert a node at front 
		void insPos(int);//To insert a node at specified position
		void delEnd();//To delete last node
		void delEle(int);//To delete a node with specified element
		void delFront();//To delete first node
		void dispList();//To display list
		int countEle();//To count no. of nodes in list
		void delNode(int);// To delete node at specified position
};
//Function to create a new node in the SLL at the end
void list::create()
{
	// implement the function; you can create and add n nodes one after the other
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

//Insert element in the SLL at the end
void list::insEnd()
{
	node *t;
	t=new node;
	cout<<"Enter integer element"<<endl;
	cin>>t->data;
	t->link=NULL;
	
	if(head==NULL)
		head=t;
	else	// move till the last node
	{
		node *t1=head;
		while(t1->link!=NULL)
			t1=t1->link;
		t1->link=t;
	}
}

//Function to insert element in the first position
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
//To insert at a particular position, you can insert after position, at position
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
//To delete last node of the SLL
void list::delEnd()
{
	// implementation
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
//To delete first node of the SLL
void list::delFront()
{
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
//To delete node at a particular position if it exists
void list::delNode(int pos)
{
	node *t,*t1;int i=1;
	t=head;
	if(t==NULL)
		cout<<"deletion not possible list is empty"<<endl;
	else if(pos>countEle() || pos<1)
	{
		cout<<"Invalid position"<<endl;
		cout<<countEle();
	}
	else		//	if position is valid
	{
		if(pos==1)
		{
			head=t->link;
			delete t;
		}
		else
		{
			for(int i=2;i<pos;i++)
			{
				t=t->link;
			}
			t1=t->link;
			t->link=t->link->link;
			delete t1;
		}
	}
}
//To display all the elements in the SLL
void list::dispList()
{
		if(head==NULL)
	{
		cout<<"the array is empty";	
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
//To ocund the elements in the list
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
int main()
{
	list l; 
	int n1,ch,pos,ele;
	while(1)
	{
		cout<<"\n\tMENU\n";
		cout<<"1. insert n nodes\n2. delete at end\n3. delete at front\n";
		cout<<"4. delete element at a position\n";
		cout<<"5. delete a specific element"<<endl;
		cout<<"6. insert at front\n7. insert at end\n8. insert at a position\n";
		cout<<"9. display\n10. exit\n";
		cout<<"enter choice\t";
		cin>>ch;
		switch(ch)
		{
			case 1: //To insert n nodes
				cout<<"enter no. of elements"<<endl;
				cin>>n1;
				for(int i=1;i<=n1;i++)
					l.create();
				break;
			case 2://delete element at end
				cout<<"delete at end \n";
				l.delEnd();
				break;
			case 3://delete at front
				l.delFront();
				break;
			case 4://delete element at a position
				cout<<"enter position of the element to be deleted\n";
				cin>>pos;
				if(pos==1)
					l.delFront();
				else
					l.delNode(pos);
				break;
			case 5://delete a specific element
					cout<<"Enter the element needed to be deleted"<<endl;
					cin>>ele;
					l.delEle(ele);
					break;	
			case 6://To insert element at start
				l.insFront();
				break;
			case 7://To insert element at end
				l.insEnd();
				break;
			case 8://To insert element at a particular position
				cout<<"\nenter position \n";
				cin>>pos;
				if(pos==1)
					l.insFront();
				else
					l.insPos(pos);
				break;
			case 9: //To display the list
				l.dispList();
				break;
			case 10://To exit
				cout << "Program ended successfully";
				exit(0);
		}
	}
	return 0;
}

