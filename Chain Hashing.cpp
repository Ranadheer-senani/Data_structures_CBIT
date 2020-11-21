#include<iostream>
using namespace std;
struct node{
    int data;
    int *next = NULL;
};
class Hash {
    int size;
    int moderator;
    struct node *Buckets;
    void insertion(int);
    void display();
    void deletion(int);
    public:
    Hash(int i =10){
        moderator = i;
        for(int k=0;k<i;k++) 
            Buckets [k]->data=NULL;
    }
};
void Hash::insertion(int inp){
    int ins = inp % moderator;
    if(Buckets [ins]->data ==NULL){
        Buckets[ins]=inp;
    }
    else{

    }
}

main(){
    Hash it;
    int a,inp;
    while(a){
        cout<<"1.Insertion\n2.Display\n3.Deletion\n0.exit"<<endl;
        if (a==1){
            cout<<"give number to be inserted"<<endl;
            cin>>inp;
            it.insertion(inp);
        }
        else if (a == 2){
            cout << "give number to be inserted" << endl;
            it.display();
        }
        else if (a==3){
            cout << "give number to be deleted" << endl;
            cin >> inp;
            it.deletion(inp);
        }
        else{
            cout<<"Invalid Expression";
            _Exit;
        }
    }
}