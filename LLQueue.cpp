#include<iostream>
using namespace std;
class node{
    int data;
    node* next;
    friend list;
};
class list{
    node* head;
    public:
    void enqueue(int);
    int dequeue();
    list();
};
list::list(){
    head=new node;
    head->next=NULL;
}
void list::enqueue(){
    node* i;
    i = head;
    while(i->next!=NULL){
        
    }
}