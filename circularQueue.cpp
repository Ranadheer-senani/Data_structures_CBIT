//Circular Queue ADT
#include<iostream>
using namespace std;
const int DefaultSize = 10;
template <class KeyType>
class cQADT
{
	public:
		cQADT(MaxQueueSize=DefaultSize){
	    //Create an empty Queue whose maximum size is MaxqueueSize
		for(int i=0;i<MaxQueueSize;i++){
			queue[i]=NULL;
		}
		front = 0;
		rear = 0;
		}
    	bool isFull(){
			return (false ? true : queue[MaxQueueSize]==NULL);
		}
		//if number of elements in the queue is equal to the maximum size of the queue, return TRUE (1); otherwise, return FALSE (0)

		void enqueueCQ(const KeyType& item){
			if(rear!=MaxQueueSize)
				queue[++rear] = item;
			else{
				cQFull();
			}
		}

    	bool isEmpty(){
    	//if number of elements in the queue is equal to 0, return TRUE (1) else return FALSE (0).
		return !(isFull);
		}
    	KeyType dequeueCQ(){
    	//if isEmpty(), then queueEmpty(); else remove and return the front element of the queue.
			KeyType a = queue[rear];
			queue[rear] = NULL;
			if (a!=NULL){
				--rear;
			}
			return a;
		}
		void rearElement(){
			cout<<queue[rear]<<" is the rear element"<<endl;
		}
		//To display TOS element

		void cQEmpty() {cout << "Circular Queue is empty nothing to pop" << endl;};
		//Queue empty display message

    	void cQFull() {cout << "Circular Queue is full no space for one more insertion" << endl;};
		//queue full display message 

    	void outputCQ() {
			for (int i = 0; i < MaxQueueSize; i++)
			{
				cout<<queue[i]<<endl;
			}
		}
		//To display the contents of queue

	private:
		int front,rear;
		KeyType *queue;
		int MaxQueueSize;
};
//Function main()
int main()
{
	cQADT <int> cQ;
	int ch;
	while(1)
	{
		cout<<"\n\n THE QUEUE OP MENU\n";
		cout<<" 1. Enqueue \n 2. Dequeue \n 3. Display rear element \n 4. Display Circular Queue \n 5. Exit";
		cout<<"\nEnter your choice\t: ";
		cin  >> ch;
		switch(ch)
		{
			case 1: //To insert an element into the Circular Queue
			{
				do
				{	
					cout<<"\nEnter an element to be inserted (other than 0) to proceed\t: ";
					cin>>ch;
				}while(ch==0);
				cQ.enqueueCQ(ch);
			}	break;
			case 2: //To delete the front element from the Circular Queue
				ch=cQ.dequeueCQ();
				if(ch!=0)
					cout<<"Element popped is\t: " <<ch<<endl;
				break;
			case 3: //Display element pointed to by rear
				cQ.rearElement();
				break;
			case 4: //To display the contents of queue
				cQ.outputCQ();
				break;
			case 5: //To exit
				cout<<"Bye Bye..";
				_exit(0);
			default:
				cout<<"Re-enter a valid option 1..5";
				break;
			}
		} //End of switch
	}//End of While
	return 0;
}

