//Problem Statement: Given two arrays arr1 of length m and arr2 of length n, check whether arr2 is a
//		     subset of arr1.

#include <iostream>
#include <unordered_map>

using namespace std;

bool array_subset_of_another_array (int arr1[], int m, int arr2[], int n);

int main()
{
	int m;
	cout << "Enter the length of the first array: ";
	cin >> m;

	int arr1[m];
	cout << "Enter the elements of the first array: ";
	for (int i = 0; i < m; i++)
		cin >> arr1[i];

	int n;
	cout << "Enter the length of the second array: ";
	cin >> n;

	int arr2[n];
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	bool ja = array_subset_of_another_array (arr1, m, arr2, n);

	if (ja)	cout << "The second array is a subset of the first." << endl;
	else	cout << "The second array is not a subset of the first." << endl;

	return 0;
}

bool array_subset_of_another_array (int arr1[], int m, int arr2[], int n)
{
	unordered_map<int, int> ump;
	
	for (int i = 0; i < m; i++)
		ump[arr1[i]]++;

	for (int i = 0; i < n; i++)
		if (ump[arr2[i]] == 0)
			return 0;

	return 1;
}
