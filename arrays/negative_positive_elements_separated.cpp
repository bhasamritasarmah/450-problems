//Problem Statement: An array consisting of both positive and negative numbers in random places is given.
//The task is to sort the array in such a way so that the negative numbers are grouped together, followed by the positive numbers.
//The order of numbers among the positive and negatives is not important here.

#include <iostream>
#include <algorithm>

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

	//If the left pointer is pointing to a positive number and the right pointer is pointing to a negative number,
	//then the two numbers are swapped. Otherwise, the pointers are just updated.
	int left = 0, right = n-1;
	while (left < right)
	{
		if (arr[left] >= 0 && arr[right] < 0)
		{
			swap(arr[left], arr[right]);
			left += 1;
			right -= 1;
		}
		else if (arr[left] < 0 && arr[right] >= 0)
		{
			left += 1;
			right -= 1;
		}
		else if (arr[left] < 0 && arr[right] < 0)
			left += 1;
		else if (arr[left] >= 0 && arr[right] >= 0)
			right -= 1;
	}

	cout << "The sorted array is given by: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
