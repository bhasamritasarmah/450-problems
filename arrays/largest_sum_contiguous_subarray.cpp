//Problem Statement: To find the largest sum of contiguous subarray of the given array.

#include <iostream>
#include <limits.h>

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

	int current_sum = 0, max_sum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		current_sum += arr[i];
		
		if (max_sum < current_sum)
			max_sum = current_sum;
	}

	cout << "The sum of the largest contiguous subarray is: " << max_sum << endl;

	return 0;
} 	
