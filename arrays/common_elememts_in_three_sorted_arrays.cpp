//Problem Statement: Given three sorted arrays, find the common elements in all the three arrays.
//		     The auxiliary space used should be constant.

#include <iostream>
#include <vector>

using namespace std;

void common_elements_in_three_arrays (int arr1[], int arr2[], int arr3[], int n1, int n2, int n3, vector<int>& intersect);

int main()
{
	int n1, n2, n3;
	cout << "Enter the sizes of the three arrays: ";
	cin >> n1 >> n2 >> n3;

	int arr1[n1], arr2[n2], arr3[n3];
	cout << "Enter the elements of the first array: ";
	for (int i = 0; i < n1; i++)
		cin >> arr1[i];
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < n2; i++)
		cin >> arr2[i];
	cout << "Enter the elements of the third array: ";
	for (int i = 0; i < n3; i++)
		cin >> arr3[i];

	vector<int> intersect;
	common_elements_in_three_arrays (arr1, arr2, arr3, n1, n2, n3, intersect);

	cout << "The common elements of all the three arrays are: ";
	for (auto x : intersect)
		cout << x << " ";
	cout << endl;

	return 0;
}

void common_elements_in_three_arrays (int arr1[], int arr2[], int arr3[], int n1, int n2, int n3, vector<int>& intersect)
{
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2 && k < n3)
	{
		if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
		{
			intersect.push_back(arr1[i]);
			i++; j++; k++;
		}
		else if (arr1[i] < arr2[j] && arr1[i] < arr3[k])
			i++;
		else if (arr2[j] < arr3[k])
			j++;
		else
			k++;
	}
}
