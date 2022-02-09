//Problem Statement: Given an array containing positive and negative integers, find out if there is
//		     a subarray whose sum is 0.

#include <iostream>
#include <unordered_map>

using namespace std;

bool subarray_sum_0 (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (subarray_sum_0 (arr, n))
		cout << "Yes, there exists a subarray with sum 0." << endl;
	else
		cout << "No, there is no subarray with sum 0." << endl;

	return 0;
}

bool subarray_sum_0 (int arr[], int n)
{
	unordered_map<int,int> ump;

	for (int i = 0; i < n; i++)
	{
		if (ump[arr[i]] == 0)	ump[arr[i]]++;
		else	return 1;
	}

	return 0;
}
