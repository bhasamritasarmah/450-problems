//Problem Statement: Given an array of integers and a value x, find the smallest subarray such that the sum
//		     of the array is greater than x.

#include <iostream>

using namespace std;

int smallest_subarray_with_sum_greater_than_given_value (int arr[], int n, int val);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int val;
	cout << "Enter the value: ";
	cin >> val;

	cout << "The length of the smallest subarray with sum greater than " << val << " is: "
		<< smallest_subarray_with_sum_greater_than_given_value (arr, n, val) << endl;

	return 0;
}

int smallest_subarray_with_sum_greater_than_given_value (int arr[], int n, int val)
{
	int left = 0, right = 0, sum = 0, min_len = n+1;

	while (right < n)
	{
		while (right < n && sum <= val && sum >= 0)
			sum += arr[right++];
		
		if (sum < 0)
		{
			left = right;
			sum = 0;
			continue;
		}

		if (sum > val && min_len > right - left)
			min_len = right - left;

		sum -= arr[left++];
	}

	return min_len;
}
