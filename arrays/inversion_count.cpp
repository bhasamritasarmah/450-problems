//Problem Statement: Given an array of integers, find the number of inversions in the array.
//		     An inversion is said to exist if a[i] > a[j] while i < j.

#include <iostream>
#include <vector>

using namespace std;

int count_inversions (int arr[], int low, int high);
int merge (int arr[], int low, int mid, int high);

int main()
{
	int n;
	cout << "Enter the size of array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The number of inversions in the array are: " << count_inversions (arr, 0, n-1) << endl;

	return 0;
}

int count_inversions (int arr[], int low, int high)
{
	int mid, inversions = 0;

	if (high > low)
	{
		mid = (low + high) / 2;

		inversions += count_inversions (arr, low, mid);
		inversions += count_inversions (arr, mid+1, high);

		inversions += merge (arr, low, mid+1, high);
	}

	return inversions;
}

int merge (int arr[], int low, int mid, int high)
{
	int i = low, j = mid, inversions = 0;
	vector<int> temp;

	while (i < mid && j <= high)
	{
		if (arr[i] <= arr[j])
			temp.push_back(arr[i++]);
		else
		{
			temp.push_back(arr[j++]);
			inversions += mid - i;	
		}
	}

	while (i < mid)
		temp.push_back(arr[i++]);

	while (j <= high)
		temp.push_back(arr[j++]);

	j = 0;
	for (i = low; i <= high; i++)
		arr[i] = temp[j++];

	return inversions;
}
