#include<iostream>	//Convert infix expression to postfix or prefix and evaluate postfix or prefix
#include<stack>		//Using stack STL
#include<algorithm>
using namespace std;
class infixOp
{
	public:
		void readInfix(char []);//Input infix expression
		void conPostfix(char [],char []);//To convert infix to postfix
		//void conPrefix(char [],char []);//To convert infix to prefix
		int evalPostfix(char []);//To evaluate postfix expression

		int priority(char);//To get the priority of operators
		void show(char []);//To output the expression
	private:
		char *expr;//To store the input expression	
};
//To return priorities of operators
int infixOp :: priority(char ch)
{
	int val;
	switch(ch)
	{
		case '*':val=1;break
		case '%':val=2;break;
		case '/':val=3;break;
		case '+':val=4;break;
		case '-':val=5;break;
		// include necessary operators
	}
	return val;
}
bool isOptr (char a){
	if (a='+'||a='-'||a='*'||a='/'||a='%')
		return true;
	else
	{
		return false;
	}
	
}
//Read infix expression
void infixOp :: readInfix(char exp[])
{
	int i=0;char ch;
	cout<<"\nenter expression ending with '#'\n";
	cin>>ch;
	while(ch!='#')
	{
		exp[i++]=ch;
		cin>>ch;
	}
	exp[i]='\0';
	
}
//To display the expression
void infixOp :: show(char exp[])
{
	int i=0;
	while(exp[i]!='\0')
	{
		cout<<"  "<<exp[i];
		++i;
	}
}
//Convert to postfix expression
void infixOp :: conPostfix(char postexp[],char exp[])
{
	//include your impmentation
	char *a;
	int k=0;
	for(int i=0;exp[i]!=0;i++){
		if((exp[i]>='0')&&(exp[i]<='9'-'0')){
			postexp[i]=exp[i];
		}
		else if(exp[i]=')'){
			postexp[i]=a[k];
		}
		else{
			if(isOptr){
				a[k]=exp[i];
				k++;
			}
		}
	}
}
//Convert infix expression into prefix expression
//void infixOp :: conPrefix(char preexp[],char exp[]){//include your implementation}

//Evaluate postfix operation
int infixOp :: evalPostfix(char postexp[])
{
	//Your implementation
	stack<int> x;
	for (int i = 0; postexp[i] != '\0'; ++i)
	{
		if (postexp[i] == '+' || postexp[i] == '/' || postexp[i] == '*' || postexp[i] == '%' || postexp[i] == '-')
		{
			int o1, o2;
			o2 = x.top();
			x.pop();
			o1 = x.top();
			x.pop();
			//cout<<endl<<"o1 is "<<o1<<endl<<"o2 is "<<o2<<endl;
			int r = doWork(postexp[i], o1, o2);
			//cout<<endl<<r;
			x.push(r);
		}
		else
		{
			string st;
			st += postexp[i];
			//cout<<endl<<"pushed"<<st;
			x.push(atoi(&st[0]));
		}
	}
	return x.top();
}
//evaluate prefix expression
//int infixOp :: evalPrefix(char preexp[]){}

int main()
{
	infixOp inf;
	char preexp[50],postexp[50],exp[50];
	int c,val;
	inf.readInfix(exp);
	while(1)
	{
		cout<<"\nGiven expression is\t: ";
		inf.show(exp);
		//cout<<"\n\n1.Infix->Postfix   2.Infix->Prefix  3.Evaluate Postfix  4.Evaluate Prefix  5.Exit\n";
		cout<<"\n\n1.Infix->Postfix   3.Evaluate Postfix  5.Exit\n";
		cout<<"enter choice\t: ";cin>>c;
		switch(c)
		{
			case 1:
				inf.conPostfix(postexp,exp);
				cout<<"\npostfix expression is:  ";
				inf.show(postexp);
				break;
			/*case 2:
				inf.conPrefix(preexp,exp);
				cout<<"\nprefix expression is:   ";
				inf.show(preexp);
				break;*/
			case 3:
				inf.conPostfix(postexp,exp);
				cout<<"\npostfix expression is:  ";
				inf.show(postexp);
				val=inf.evalPostfix(postexp);
				cout<<"\n evaluated postfix expression value is:  ";
				cout<<val;
				break;
			/*case 4:
				inf.conPrefix(preexp,exp);
				cout<<"\nprefix expression is:  ";
				inf.show(preexp);
				val=inf.evalPrefix(preexp);
				cout<<"\n evaluated prefix expression value is:  ";
				cout<<val;
				break;*/ 
			default:
				exit(0);
		}
	}
	return 0;
}
