//Problem Statement: Given an array of numbers, rearrange the numbers into lexicographically next greater
//		     permutation of numbers.

#include <iostream>
#include <algorithm>

using namespace std;

void lexicographically_next_greater_permutation (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	lexicographically_next_greater_permutation (arr, n);
	cout << "The lexicographically next greater permutation of numbers is: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

void lexicographically_next_greater_permutation (int arr[], int n)
{
	int flag = 0;

	for (int i = n-1; i > 0; i--)
		if (arr[i] > arr[i-1])
		{
			swap (arr[i], arr[i-1]);
			flag = 1;
			break;
		}

	if (flag == 0)
		for (int i = 0; i < n/2; i++)
			swap (arr[i], arr[n-i-1]);
}
