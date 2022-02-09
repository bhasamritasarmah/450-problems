//Problem Statement: Given an array arr and a range [a, b], the task is to partition the array into 3 parts -
//		     The first part contains all the values less than a.
//		     The second part contains all the values in range a and b.
//		     The third part contains all the values greater than b.

#include <iostream>
#include <algorithm>

using namespace std;

void three_way_partitioning (int arr[], int n, int lb, int ub);

int main()
{
	int n; 
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int lb, ub;
	cout << "Enter the lower and upper bounds of the range respectively: ";
	cin >> lb >> ub;

	three_way_partitioning (arr, n, lb, ub);

	cout << "The modified array is: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

void three_way_partitioning (int arr[], int n, int lb, int ub)
{
	int less = 0, more = n-1, i = 0;

	while (i <= more)
	{
		if (arr[i] < lb)
		{
			if (i == less)
			{
				i++; less++;
			}
			else
				swap (arr[i++], arr[less++]);
		}
		else if (arr[i] > ub)
			swap (arr[i], arr[more--]);
		else
			i++;
		
		cout << "i = " << i << " less = " << less << " more = " << more << endl;
		for (int j = 0; j < n; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
}
