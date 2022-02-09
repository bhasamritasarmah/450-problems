//This program takes in an array of integers containing only 0s, 1s, and 2s
//It then outputs the sorted array. No sorting algorithm is used to sort this array.
//The sorting done here is not a stable sorting.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//Three variables are declared to hold the number of 0s, 1s, and 2s
	int zeros = 0, ones = 0, twos = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			zeros += 1;
		else if (arr[i] == 1)
			ones += 1;
		else
			twos += 1;
	}

	//The array is filled first with the required number of zeros, then with 1s, followed by 2s.
	int i;
	for (i = 0; i < zeros; i++)
		arr[i] = 0;

	for (; i < zeros + ones; i++)
		arr[i] = 1;

	for (; i < zeros + ones + twos; i++)
		arr[i] = 2;

	cout << "The elements of the array are: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	return 0;
} 
