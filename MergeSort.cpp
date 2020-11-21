#include <iostream>
using namespace std;

void merge(int *a, int *b, int *main, int sizef, int sizes)
{
	int i = 0, j = 0, k = 0;
	while (i < sizef && j < sizes)
	{
		if (a[i] < b[j])
			main[k++] = a[i++];
		else
			main[k++] = b[j++];
	}
	while (i < sizef)
	{
		main[k++] = a[i++];
	}
	while (i > sizes)
	{
		main[k++] = b[j++];
	}
}

void mergesort(int *main, int s)
{
	if (s == 1)
		return;
	int i, mid = s / 2;
	int firsthalf[mid], sechalf[s - mid];
	for (i = 0; i < mid; ++i)
	{
		firsthalf[i] = main[i];
	}
	for (; i < s; ++i)
	{
		sechalf[i - mid] = main[i];
	}
	mergesort(firsthalf, mid);
	mergesort(sechalf, s - mid);
	merge(firsthalf, sechalf, main, mid, (s - mid));
}

main()
{
	int size;
	cout << "Give size of array" << endl;
	cin >> size;
	int A[size];
	cout << "Input elements" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	mergesort(A, size);
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}