//Arrray ADT Program
#include <iostream>
#include <unistd.h> //for _exit(0)
#include <stdlib.h> //for system()
using namespace std;
//Array class ADT
class cppArray
{
private:
	int *array;	   //Pointer to array
	int n;		   //size of array
	int lastIndex; //
public:
	cppArray(int size);					 //Constructor
	bool rangeCheck(int i);				 //Check whether i is a valid index; returns true if valid index; false otherwise
	bool isFull(int index);				 //check if array has atleast one location free to insert an element, returns true if array is full; false otherwise
	bool isEmpty();						 //check whether array has atleast one element to delete; returns true if array is empty; false otherwise
	int insertEle(int index, int value); //Overwriting
	bool delEle(int index);				 //Delete element at a particular index - Shift the elements left
	void display();						 // Print the array
	void sort(bool asc);				 // if asc = true perform ascending sort if false descending sort
	void inpt(int s);					 // loading array
	void getSize();
}; //End of array ADT

//function implementation follows
cppArray::cppArray(int size)
{
	array = new int[size];
	n = size;
	lastIndex = -1;
}

void cppArray::inpt(int s)
{
	cout << "give input";
	for (int i = 0; i < s; i++)
	{
		cin >> array[i];
	}
	lastIndex = s - 1;
}
void cppArray::getSize()
{
	cout << n;
}
bool cppArray::rangeCheck(int i)
{
	if ((i < n) && (i >= 0))
		return true;
	else
		return false;
}

bool cppArray::isFull(int index)
{
	if (lastIndex == n - 1)
		return true;
	else
		return false;
}

bool cppArray::isEmpty()
{
	if (lastIndex == -1)
		return true;
	else
		return false;
}
int cppArray::insertEle(int index, int value)
{
	for (int i = lastIndex; i >= index; i--)
	{
		array[i + 1] = array[i];
	}
	array[index] = value;
	lastIndex = lastIndex + 1;
}

bool cppArray::delEle(int index)
{
	int ele = array[index];
	for (int i = index; i < lastIndex; i++)
	{
		array[i] = array[i + 1];
	}
	lastIndex = lastIndex - 1;
	return ele;
}

void cppArray::display()
{

	for (int i = 0; i <= lastIndex; i++)
	{
		cout << array[i] << endl;
	}
}

void cppArray::sort(bool asc)
{
	if (asc == true)
	{
		for (int j = 0; j < lastIndex; j++)
		{
			int min = j;
			for (int i = j + 1; i <= lastIndex; i++)
			{
				if (array[i] < array[min])
					min = i;
			}
			int temp;
			temp = array[j];
			array[j] = array[min];
			array[min] = temp;
		}
	}

	else
	{

		for (int j = 0; j < lastIndex; j++)
		{
			int max = j;
			for (int i = j + 1; i <= lastIndex; i++)
			{
				if (array[i] > array[max])
					max = i;
			}
			int temp;
			temp = array[j];
			array[j] = array[max];
			array[max] = temp;
		}
	}
}
//Function main()
int main()
{
	int n1, k, ch = 1, s;
	int index, value;
	cppArray a1(5);

	//Write the code to input values for the array
	cout << "Give the number of input values required for array";
	cin >> s;
	a1.inpt(s);

	system("clear");
	while (1)
	{

		cout << endl
			 << "\t THE MENU" << endl;
		cout << endl
			 << "1. Insert <index, value>" << endl
			 << "2. Echo array" << endl
			 << "3. GetSize()" << endl
			 << "4. Delete element";
		cout << endl
			 << "5. Sort the elements of the array" << endl
			 << "*. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: //To insert element at a specified index
		{
			cout << "Enter the <index,value> pair: ";
			cin >> index >> value;
			bool result1 = a1.rangeCheck(index);
			bool result2 = a1.isFull(index);
			if (result1 && !result2)
			{
				a1.insertEle(index, value);
				cout << value << " successfully accommodated in the index" << index;
			}
			else
			{
				cout << "invalid index"
					 << "\n";
				cout << "unable to insert" << endl;
			}
		}
		break;

		case 2: //To display the contents of the array
		{
			a1.display();
		}
		break;

		case 3: //To get the size of the array
		{
			a1.getSize();
		}
		break;

		case 4: //Sort the elements of the array
		{
			bool a;
			cout << "Enter true for ascending, false for descending";
			cin >> a;
			a1.sort(a);
		}
		break;
		case 5: //Delete element
		{
			int ind;
			cout << "Enter index value";
			cin >> ind;
			bool res = a1.isEmpty();
			if (!res)
			{
				int ele = a1.delEle(ind);
				cout << ele << " successfully deleted";
			}
		}
		break;
		default: //Default case
		{
			cout << "Exiting";
			_exit(0);
		}
		} //End of Switch
	}	  //End of while
	return 0;
} //End of main()