//Problem Statement: Given an array of integers, find the largest subarray, containing at least one element,
//		     which has the maximum sum.

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int max_sum_subarray (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The maximum sum of subarray is: " << max_sum_subarray (arr, n) << endl;
	
	return 0;
}

int max_sum_subarray (int arr[], int n)
{
	int max_sum = arr[0], curr_sum = arr[0];

	for (int i = 1; i < n; i++)
	{
		curr_sum = max (arr[i], curr_sum + arr[i]);
		max_sum = max (max_sum, curr_sum);	
	}

	return max_sum;
}		
				
