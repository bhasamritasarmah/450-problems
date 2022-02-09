//Problem Statement: Given an array of integers, where each integer denotes the maximum number of steps
//		     that can be taken from that point, find the minimum number of steps that needs to
//		     be taken to reach the end.

#include <iostream>
#include <limits.h>

using namespace std;

int min_steps(int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The minimum number of steps that needs to be taken is " << min_steps(arr, n) << endl;

	return 0;
}

int min_steps (int arr[], int n)
{
	if (n == 1)	return 0;

	int min_jump = INT_MAX;
	for (int i = n-2; i >= 0; i--)
	{
		if (arr[i] + i >= n-1)
		{
			int jumps = min_steps (arr, i+1);
	
			if (jumps != INT_MAX)
				min_jump = min (min_jump, jumps + 1);
		}
	}

	return min_jump;
}	
