//Problem Statement: Two sets of integers are given. The task is to print the intersection of the two sets.

#include <iostream>
#include <algorithm>

using namespace std;

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

	//Sorting the two arrays for ease of computation
	sort (arr1, arr1+m);
	sort (arr2, arr2+n);

	//If the elements in both the arrays are same, it is added to the intersection array.
	//If the elements in both the arrays are not same, then the pointer for the array which contains the smaller element is incrememted.
	int p = max(m, n);
	int intersection[p];
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (arr1[i] == arr2[j])
		{
			intersection[k] = arr1[i];
			i++;	j++;	k++;
		}
		else if (arr1[i] < arr2[j])
			i++;
		else if (arr1[i] > arr2[j])
			j++;
	}

	cout << "The intersection of two sets is: ";
	for (i = 0; i < k; i++)
		cout << intersection[i] << " ";
	cout << endl;

	return 0;
}
