//Problem Statement: Given an array, find a triplet so that their sum is equal to the given number.

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

	int sum;
	cout << "Enter the required sum: ";
	cin >> sum;

	sort (arr, arr+n);
	
	int i, left, right, flag;
	for (i = 0; i < n-2; i++)
	{
		left = i+1; right = n-1;
		while (left < right)
		{
			if (arr[left] + arr[right] == sum - arr[i])
			{
				flag = 1;
				break;
			}
			else if (arr[left] + arr[right] < sum - arr[i])
				left++;
			else if (arr[left] + arr[right] > sum - arr[i])
				right--;
		}
		
		if (flag == 1)	break;
	}

	if (flag == 1)
		cout << "The triplet " << arr[i] << ", " << arr[left] << ", " << arr[right] << " sums up to the given sum. " << endl;
	else
		cout << "No such triplet exists. " << endl;

	return 0;
}
