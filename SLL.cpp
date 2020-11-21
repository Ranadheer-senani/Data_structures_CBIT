//Program to implement Single Linked List
#include <iostream>
using namespace std;
class list; //forward Declaration
class node
{
    friend class list;

private:
    int data;   //data part
    node *link; //link part
};

class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void create();    //To create a list with n nodes
    void insEnd();    //To insert a node at end
    void insFront();  //To insert a node at front
    void insPos(int); //To insert a node at specified position
    void delEnd();    //To delete last node
    void delEle(int); //To delete a node with specified element
    void delFront();  //To delete first node
    void dispList();  //To display list
    int countEle();   //To count no. of nodes in list
};
//Function to create a new node in the SLL at the end
void list::create()
{
    // implement the function; you can create and add n nodes one after the other
    node *t = new node;
    cout << "enter the element" << endl;
    cin >> t->data;
    t->link = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        node *n = head;
        while (n->link != NULL)
        {
            n = n->link;
        }
        n->link = t;
    }
}

//Insert element in the SLL at the end
void list::insEnd()
{
    node *t;
    t = new node;
    cout << "Enter integer element : ";
    cin >> t->data;
    t->link = NULL;

    if (head == NULL)
        head = t;
    else // move till the last node
    {
        node *t1 = head;
        while (t1->link != NULL)
            t1 = t1->link;
        t1->link = t;
    }
}

//Function to insert element in the first position
void list::insFront()
{
    node *t;
    int x;
    t = new node;
    cout << "\nenter element\n";
    cin >> t->data;
    t->link = NULL;
    if (head != NULL)
        t->link = head;
    head = t;
}
//To insert at a particular position, you can insert after position, at position
void list::insPos(int pos)
{
    node *prev = new node();
    node *curr = new node();
    node *newNode = new node();
    cout << "\nenter element : ";
    cin >> newNode->data;

    int tempPos = 0;

    curr = head;
    if (head != NULL)
    {
        while (curr->link != NULL && tempPos != pos)
        {
            prev = curr;
            curr = curr->link;
            tempPos++;
        }
        node *t;
        int ele, i = 1;
        t = new node;
        int totalele = countEle();
        if (pos > totalele || pos < 1)
        {
            cout << "Invalid position" << endl;
        }
        else // if the position is valid .....
        {
            prev->link = newNode;
            newNode->link = curr;
            cout << "Node added at position: " << pos << endl;
        }
    }
}
//To delete last node of the SLL
void list::delEnd()
{
    if (head == NULL)
    {
        cout << "SLL is empty" << endl;
    }
    else if (head->link == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *t = head;
        while (t->link->link != NULL)
        {
            t = t->link;
        }
        delete t->link;
        t->link = NULL;
    } // implementation
}
//To delete first node of the SLL
void list::delFront()
{
    node *t, *t1;
    t = head;
    if (t == NULL)
        cout << "SLL underflow" << endl;
    else
    {
        t = head;
        t1 = head->link;
        head = t1;
        delete t;
    }
}
//To delete node at a particular position if it exists
void list::delEle(int pos)
{
    node *t, *t1;
    int i = 1;
    t = head;
    if (t == NULL)
        cout << "deletion not possible list is empty" << endl;
    else if (pos > countEle() || pos < 1)
    {
        cout << "Invalid position" << endl;
    }
    else // if position is valid
    {
        if (pos == 0)
        {
            head = t->link;
            delete t;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                t = t->link;
            }
            t1 = t->link;
            t->link = t->link->link;
            delete t1;
        }
    } //provide your logic here
}
//To display all the elements in the SLL
void list::dispList()
{
    node *t;
    t = head;
    if (head == NULL)
        cout << "List is empty" << endl;
    else
    {
        while (t != NULL)
        {
            cout << endl
                 << t->data;
            t = t->link;
        }
    }
}
//To ocund the elements in the list
int list::countEle()
{
    int count = 1;
    node *t;
    t = head;
    while (t != NULL)
    {
        count += 1;
        t = t->link;
    }
    return count;
}
int main()
{
    list l;
    int val, n1, ch, pos;
    while (1)
    {
        cout << "\n\tMENU\n";
        cout << "1. insert n nodes\n2. delete at end\n3. delete at front\n";
        cout << "4. delete element at a position\n";
        cout << "5. insert at front\n6. insert at end\n7. insert at a position\n";
        cout << "8. display\n9. exit\n";
        cout << "enter choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1: //To insert n nodes
            cout<<"enter no. of elements"<<endl;
				cin>>n1;
				for(int i=1;i<=n1;i++)
					l.create();
				break;
        case 2: //delete element at end
            cout << "delete at end \n";
            l.delEnd();
            break;
        case 3: //delete at front
            l.delFront();
            break;
        case 4: //delete element at a position
            cout << "enter position of the element to be deleted\n";
            cin >> pos;
            if (pos == 1)
                l.delFront();
            else
                l.delEle(pos);
            break;
        case 5: //To insert element at start
            l.insFront();
            break;
        case 6: //To insert element at end
            l.insEnd();
            break;
        case 7: //To insert element at a particular position
            cout << "\nenter position \n";
            cin >> pos;
            if (pos == 1)
                l.insFront();
            else
                l.insPos(pos);
            break;
        case 8: //To display the list
            l.dispList();
            break;
        case 9: //To exit
            exit(0);
        }
    }
    return 0;
}
