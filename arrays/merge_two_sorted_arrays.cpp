//Problem Statement: Given two sorted arrays of size m and n, merge the two arrays
//		     so that the final array is also sorted.
//Constraints: (1) Expected space complexity: Theta(1), i.e. The smallest m numbers should be in the first array,
//		   and the rest of the numbers should be in the second array. (2) Expected time complexity: Theta(n)

#include <iostream>
#include <algorithm>

using namespace std;

void merge_sorted_arrays (int arr1[], int arr2[], int m, int n);
int main()
{
	int m, n;
	cout << "Enter the size of the first array: ";
	cin >> m;
	cout << "Enter the size of the second array: ";
	cin >> n;

	int arr1[m], arr2[n];
	cout << "Enter the elements of the first array: ";
	for (int i = 0; i < m; i++)
		cin >> arr1[i];
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	merge_sorted_arrays (arr1, arr2, m, n);

	cout << "The final sorted array is: " << endl;
	for (int i = 0; i < m; i++)
		cout << arr1[i] << " ";
	for (int i = 0; i < n; i++)
		cout << arr2[i] << " ";
	cout << endl;

	return 0;
}

void merge_sorted_arrays (int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;

	while (i < m && j < n)
	{
		if (arr1[i] <= arr2[j])
		{
			i++; continue;
		}

		swap(arr1[i], arr2[j]);
		i++;
		if (j < n-1 && arr2[j+1] < arr2[j])
		{
			int temp = arr2[j];
			int k = j+1;
			while (arr2[k] < temp && k < n)
			{
				arr2[k-1] = arr2[k];
				k++;
			}
			arr2[k-1] = temp;
		}
	}
}
