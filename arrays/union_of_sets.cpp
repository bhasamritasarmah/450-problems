//Problem Statement: Two sets of integers are given. Find the union of the two sets.
//If an element occurs in both the arrays then only one occurence of the element should be there in the union array.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int m, n;
	cout << "Enter the size of the first set: ";
	cin >> m;
	cout << "Enter the size of the second set: ";
	cin >> n;
	
	int arr1[m], arr2[n];
	cout << "Enter the elements of the first set: ";
	for (int i = 0; i < m; i++)
		cin >> arr1[i];
	cout << "Enter the elements of the second set: ";
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	//Sorting both the arrays for ease of computation
	sort (arr1, arr1+m);
	sort (arr2, arr2+n);

	//If the element is present in both the arrays, then include it only once and update the pointers.
	//If the element in the first array is smaller than the element in the second array, then include that element and increment the pointer of the first array.
	//If the element in the second array is smalller than the element in the first array, then include that element and increment the pointer of the second array.	
	int p = m + n;
	int union_set[p];
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (arr1[i] == arr2[j])
		{
			union_set[k] = arr1[i];
			i++;	j++;	k++;
		}
		else if (arr1[i] < arr2[j])
			union_set[k++] = arr1[i++];
		else if (arr1[i] > arr2[j])
			union_set[k++] = arr2[j++];
	}

	if (i < m)
		for (; i < m; i++)
			union_set[k++] = arr1[i];
	if (j < n)
		for (; j < n; j++)
			union_set[k++] = arr2[j];

	cout << "The union of the two sets is: ";
	for (i = 0; i < k; i++)
		cout << union_set[i] << " ";
	cout << endl;

	return 0;
}
