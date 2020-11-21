#include<iostream>
#include<algorithm>
using namespace std;

//Abstract Data Type of String
class StringADT
{
	public: 
		StringADT(char *init, int m);
		//Constructor that initializes *this to string init of length m
		
		StringADT(char *init);
		//Constructor that initializes *this to init and assigns length of init to length		

		StringADT(int m);
		//Constrcutor that creates a string with length m which is empty;
		
		StringADT(){};
		//Default Constructor

		bool operator ==(StringADT t);
		//If the string represented by *this equals t, return true;else return false

		bool operator!();
		//If *this is empty then return true; else return false

		int Length();
		//Return the number of characters in *this;

		void Concat(StringADT t);
		//Return a string whose elements are those of *this followed by those of t;		
		
		StringADT Substr(int i, int j);
		//Return a string containing the j characters of *this 
		//at positions i, i+1, ..., i+j-1 if these are valid positions of *this; 
		//otherwise, throw an exception

		int Find(StringADT pattern);
		//Return an index i such that pattern matches the substring of *this 
		//that begins at position i. 
		//Return -1 if pattern is either empty or not a substring of *this

		int BMMatch(StringADT);
		//Boyer Moore Pattern Algorithm for fast finding a pattern using last function
		
		void last(StringADT pattern, int *,int);
		//To calculate last values for each index of pattern for FastFind()

		
		void display();
		//To display the string
		
		~StringADT(){};
	private:
		int length;
		char *str;
};//End of StringADT

//Implementation of the above StringADT specification

//Constructor that initialises *this to string init to length m
StringADT::StringADT(char *init, int m)
{
	str=init;
	length=m;
}

//Constructor with only one argument
StringADT::StringADT(char *init)
{
	str=init;
	length=Length();
}

StringADT::StringADT(int m)
{
	str=new char[m+1];//+1 for accommodating null character
	length=m;
}
//To check if *this equals string t returns true if equal otherwise false
bool StringADT::operator ==(StringADT t)
{
	if(this==&t)
	{
		return true;
	}
	else if (length==t.Length())
	{
		int i=0;
		for(;(i<length) && (str[i]==t.str[i]);i++);
		if(i==length)
		{
			return true;
		}
		else
		{	
			return false;
			
		}
	}
	else
		return false;
}
	
//To check if *this is empty; if empty return true otherwise return false
bool StringADT::operator !()
{
	if(Length()==0)
		return true;
	else
		return false;
}

//To calculate string length
int StringADT::Length()
{
	int i=0;
	for(;str[i]!='\0';i++);
	return i;
}

//To concatenate two string
void StringADT::Concat(StringADT t)
{
	int i=0,j=0;
	for(i=0;i<Length();i++);
	for(j=0;j<t.Length();j++,i++)
		*(str+i)=*(t.str+j);
	*(str+i)='\0';
}

//Function to extract substring from *this; starting from position i, j characters
StringADT StringADT::Substr(int i, int j)
{
	StringADT temp("invalid i and j values");
	char *t=str+i;
	char *s=new char[j+1];
	int k=i+j;
	int l=0;
	if(Length()>k)
	{
		while(i<k)
		{                                             
			*(s+l)=*(t+l);
			i++;	
			l++;
		}
		s[i]='\0';
		StringADT temp1(s);
		cout<<"Substring is "<<s<<endl;
		return temp1;
	}
	else
		return temp;

}

//Function to exhaustive search a Pattern in *this
int StringADT::Find(StringADT pattern)
{
	for(int i=0;i<=length-pattern.length+1;i++)
	{
		int flag=1;
		for(int j=0;j<pattern.length;j++)
		{
			if(str[i+j]!=pattern.str[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			return i;	 		
	}
	return -1;
}

//Booyer moore Algorithm to search for a pattern
int StringADT::BMMatch( StringADT pattern)
{   
		int i,j;
		i=j=pattern.length-1;
		int badChar[256];
		last(pattern,badChar,256); // preprocessing
		while(i<length)
		{
			if(str[i]==pattern.str[j])
			{
				if(j==0)
					return i;
				else
				{
					i--;
					j--;	
				}	
			}
			else
			{
				i=i+pattern.length-min(j,1+badChar[int(str[i])]);
				j=pattern.length-1;
			}
		}
		return -1;
}

//To compute last values for the pattern
void  StringADT::last(StringADT pattern, int* badChar,int n)
{
		for(int i=0;i<256;i++)
		{
			badChar[i]=-1; //initialising -1 to all characters
		}
		for(int i=0;i<pattern.length;i++)
		{
			badChar[int(pattern.str[i])]=i;  //initialising the last occurance of each character in pattern			
		}
}

void StringADT::display()
{
	cout<<str;
}
//main() with menu
int main()
{
	int ch,i,j;
	char s1[100],s2[100];
	while(1)
	{
		cout<<endl<<" 1. Fast find a pattern using Boyer Moore alg\n 2. Find a pattern\n 3. Find a substring\n 4. Concatenate 2 strings\n ";
		cout<<"5. Check whether 2 strings are equal\n 6. Check if a string has 0 length\n 7. Find length of the string\n ";
		cout<<"8. Display the string\n 9. Exit"<<endl;
	
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:	//To Boyer  Moore Algorithm (fast find a pattern)
			{	cout<<"Enter a main string: ";
				cin>>s1;
				StringADT s(s1);
				cout<<"Enter the pattern to be searched: ";
				cin>>s2;
				StringADT p(s2);
				ch=s.BMMatch(p);
				if(ch>-1)
					cout<<s2<<" found at index "<<ch<<endl;
				else
					cout<<"Pattern not found"<<endl;
			}	break;
			case 2: //To exhaustive search a pattern
			{	cout<<"Enter a main string: ";
				cin>>s1;
				StringADT a(s1);
				cout<<"Enter the pattern to be searched: ";
				cin>>s2;
				StringADT b(s2);
				ch=a.Find(b);
				if(ch>-1)
					cout<<s2<<" found at index "<<ch<<endl;
				else
					cout<<"Pattern not found"<<endl;
			}	break;
			case 3: //To find a substring
			{	cout<<"Enter the main string";
				cin>>s1;
				StringADT c(s1);
				cout<<"Enter the position and no. of characters to be extracted\n";
				cin>>i>>j;
				StringADT res=c.Substr(i,j);
				cout<<"Extracted sub string is\t: ";
				res.display();			
				cout<<endl;
			}	break;
			case 4: //To concatenate two strings
			{	cout<<"Enter first string: ";
				cin>>s1;
				StringADT d(s1);
				cout<<"Enter the second string: ";
				cin>>s2;
				StringADT e(s2);
				d.Concat(e);
				cout<<"The concatenated string is..: ";
				d.display();
			}	break;
			case 5: //To check whether 2 strings are equal
			{	cout<<"Enter the two strings to be compared"<<endl;
				cout<<"String #1 = ";
				cin>>s1;
				StringADT f(s1);
				cout<<"String #2 = ";
				cin>>s2;
				StringADT g(s2);
				if(f==g)
					cout<<"\nBoth strings are equal"<<endl;
				else
					cout<<"\nBoth strings are not equal"<<endl;
			}	break;
			case 6: //To check if string length is 0
			{	cout<<"If u want to enter a nonzero length string after giving option 6, immediately input the string without pressing enter";
				cout<<endl<<"Enter the string\t: ";
				cin.getline(s1,100,'\n');
				StringADT h(s1);
				if(!h)
					cout<<"\nString Length is 0 "<<endl;
				else
				{
					h.display();
					cout<<"\nString Length is not 0 " << endl;
				}
			}	break;
			case 7: //To find length of the string
			{	cout<<"Enter the string for which length is required\t: ";
				cin>>s1;
				StringADT k(s1);
				cout<<"\nLength of s1 is .."<<k.Length();
			}	break;
			case 8: //To display the string
			{	cout<<"Enter the string to be displayed\t: ";
				cin>>s1;
				StringADT l(s1);
				l.display();
			}	break;
			case 9: //Time to say goodbye
			{	cout<<"bye bye...";
				_exit(0);
			}	break;
			default: //To hint invalid option
			{	cout<<"\nInvalid option only 1..9";
			}	break;
		}//End of switch
	}//End of while
	return 0;
}//End of main()

