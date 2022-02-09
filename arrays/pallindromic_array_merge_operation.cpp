//Problem Statement: Given an array of integers, find the minimum number of merge operations needed to make the array
//		     a pallindromic array. Merge operation means adding two consecutive numbers together to make one number.

#include <iostream>

using namespace std;

int min_ops_pallindromic (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << "The minimum number of operations needed to make the array pallindromic is: " << min_ops_pallindromic (arr, n);
	cout << endl;

	return 0;
}

int min_ops_pallindromic (int arr[], int n)
{
	int i = 0, j = n-1, ops = 0;

	while (i != j)
	{
		if (arr[i] == arr[j])
		{
			i++;	j--;
		}
		else if (arr[i] < arr[j])
		{
			arr[i+1] += arr[i++];
			ops++;
		}
		else if (arr[i] > arr[j])
		{
			arr[j-1] += arr[j--];
			ops++;
		}
	}

	return ops;
}
