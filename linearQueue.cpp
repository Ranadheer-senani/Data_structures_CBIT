//Implementing Linear Queue using Linked List
#include<iostream>
#include <unistd.h> //for _exit(0)
using namespace std;
class queue
{
	class Qnode
	{
		public:
			char ele;
			Qnode *link;
	};
	public:
		Qnode *f,*r;
		queue()
		{
			f=NULL;
			r=NULL;
		}
		void enqueue(char);//To insert into a Queue
		char  dequeue();//To delete from a Queue
		void disQ();//To display Queue contents
		bool IsEmpty();//To check if Queue is empty
		char front();//To display the element pointed to be front pointer
};
void queue::enqueue(char){
	Qnode *a = new Qnode;
	cout<<"give your required element to be stored"<<endl;
	if(f==NULL){
		f = a;
	}
	cin >> a->ele;
	a->link = NULL;
	r = a;
}
char queue::dequeue(){
	Qnode *a = new Qnode;
	a=f;
	while(a->link!=NULL){
		a=a->link;
	}
	a->link=NULL;
}
void queue::disQ(){
	Qnode *a = new Qnode;
	a = f;
	while (a->link != NULL)
	{
		cout<<(a->ele)<<endl;
		a = a->link;
	}
	cout<<(r->ele)<<endl;
}
bool queue::IsEmpty(){
	return (true ? false : f==NULL);
}
char queue::front(){
	return ("Empty" ? f->ele : f==NULL);
}
main(){
	queue q;
	char a;
	int ch;
	while(1){
		cout<<"     Choose Options"<<endl;
		cout << "1.To insert into a Queue"<<endl;
		cout << "2.To delete from a Queue" << endl;
		cout << "3.To display Queue contents" << endl;
		cout << "4.To check if Queue is empty" << endl;
		cout << "5.To display the element pointed to be front pointer \n" <<"*.Exit"<< endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch){
			case 1:
			{
				cout<<"Give the element you want to enter :"<<endl;
				cin>>a;
				q.enqueue(a);
				break;
			}
			case 2:
			{
				cout<<" The Dequeued element is :"<<q.dequeue()<<endl;
				break;
			}
			case 3:
			{
				cout<<"Displaying queue :"<<endl;
				q.disQ();
				break;
			}
			case 4:
			{
				cout<<"The Queue is ";
				if(q.IsEmpty()){
					cout<<"not ";
				}
				cout<<"empty"<<endl;
				break;
			}
			case 5:
			{
				cout<<"Front of Queue is "<<q.front();
				break;
			}
			default: //Default case
			{	cout<<"Exiting";
				_exit(0);
			}
		}
	}
	return 0;
}