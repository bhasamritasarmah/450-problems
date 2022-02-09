//Problem Statement: Given an array of integers and a number k, find out the minimum number of swaps required
//		     to bring all the elements less than k together.

#include <iostream>

using namespace std;

int min_swaps_and_k (int arr[], int n, int k);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k;
	cout << "Enter the value of k: ";
	cin >> k;

	cout << "The minimum number of swaps required is: " << min_swaps_and_k (arr, n, k) << endl;

	return 0;
}

int min_swaps_and_k (int arr[], int n, int k)
{
	int count = 0;

	//The number of elements less than k are counted and the value is stored in variable count
	for (int i = 0; i < n; i++)
		if (arr[i] <= k)	count++;
	
	int swaps = 0, j = 0, i;

	for (i = 0; i < count; i++)
		if (arr[i] > k) swaps++;
	
	int min_swaps = swaps;

	for (; i < n; i++)
	{
		if (arr[j++] > k)	swaps--;
		if (arr[i] > k) 	swaps++;
		
		if (swaps < min_swaps)	min_swaps = swaps;
	}
	
	return min_swaps;
}
