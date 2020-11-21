#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
class trie;
class node
{
	node *child[26];
	bool end;
	friend class trie;
	node()
	{
		end = false;
	}
};
class trie
{
	node *root;

public:
	trie()
	{
		root = new node;
		root->end = false;
	}
	void insert(string);
	bool search();
	void display();
	void displayD(node *, char *, int);
};

void trie::insert(string const data)
{
	node *t = root;
	int i, c = 0;
	//Your code here
	for (i = 0; data[i] != '\0'; i++)
	{
		c = int(data[i] - 65);
		//t->child[c] = data[i];
		t = t->child[c];
	}
	if (data[i--] == '0')
	{
		t->end = true;
	}
}

bool trie::search()
{
	node *t = root;
	string data;
	int i, c, j = 0;
	bool flag = false;
	cout << "enter the string to be searched...\n";
	cin >> data;
	//Your code here
	for (i = 0; data[i] != '\0'; ++i)
	{
		c = int(data[i] - 65);
		if (t->child[c])
		{
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}
		t = t->child[c];
	}
	return flag;
}
void trie::display()
{
	int l = 0;
	char str[100];
	displayD(root, str, l);
}
void trie::displayD(node *r, char *str, int l)
{
	if (r->end == true)
	{
		str[l] = '\0';
		cout << str << "\n";
	}
	int i;
	for (i = 0; i < 25; i++)
	{
		if (r->child[i])
		{
			str[l] = i + 'a';
			displayD(r->child[i], str, l + 1);
		}
	}
}
int main()
{
	trie t;
	string data;
	int n;
	while (1)
	{
		cout << "\n1.Insert \n2.Search \n3.Display \n4.Exit\n";
		cout << "enter choice\n";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "give a word in capital letters to insert :" << endl;
			cin >> data;
			t.insert(data);
			break;
		}
		case 2:
		{
			if (t.search())
				cout << "Found!!!" << endl;
			else
			{
				cout << "Not Found :(" << endl;
			}

			break;
		}
		case 3:
		{
			t.display();
			break;
		}
		case 4:
		{
			_Exit;
		}
		}
	}
	return 0;
}
