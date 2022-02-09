//Problem Statement: Given an array of integers where every element represents the maximum number of steps
//		     that can be taken forward from that element. The task is to find the minimum number of
//   		     jumps to reach to the end.

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int min_steps (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The minimum number of steps to reach the end is: " << min_steps(arr, n) << endl;

	return 0;
}

int min_steps (int arr[], int n)
{
	int min_jumps[n] = {INT_MAX};
	min_jumps[0] = 0;
	int jumps = arr[0];
	int end;

	cout << "The elements of the min_jumps array are: " << endl;
	for (int i = 0; i < n; i++)
		cout << min_jumps[i] << " ";
	cout << endl;

	for (int i = 1; i < n; i++)
	{
		end = arr[i-1] + 1;
		for (int j = i; j <= end; j++)
			min_jumps[j] = min(min_jumps[j], min_jumps[i]+1);

		cout << "The elements of the min_jumps array are: " << endl;
		for (int i = 0; i < n; i++)
			cout << min_jumps[i] << " ";
		cout << endl;
	}
	
	return min_jumps[n-1];
}		
