//Problem Statement: Given an array of integers (positive, negative, and 0), find the subarray
//		     containing the elements which give the largest product.

#include <iostream>
#include <algorithm>

using namespace std;

int max_prod_subarray (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The maximum product is " << max_prod_subarray (arr, n) << endl;

	return 0;
}

int max_prod_subarray (int arr[], int n)
{
	int curr_max = 1, curr_min = 1, final_max = 0, flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			curr_max *= arr[i];
			curr_min = min (curr_min * arr[i], 1);
			flag = 1;
		}
		else if (arr[i] == 0)
		{
			curr_max = 1;
			curr_min = 1;
		}
		else if (arr[i] < 0)
		{
			int temp = curr_max;
			curr_max = max (curr_min * arr[i], 1);
			curr_min = temp * arr[i];
		}
		
		if (final_max < curr_max)	final_max = curr_max;
	}

	if (flag == 0 && final_max == 0)	return 0;

	return final_max;
}
