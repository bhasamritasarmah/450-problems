//Problem Statement: Given an array of positive integers, find the longest subsequence that has consecutive numbers.
//		     The consecutive numbers can be in any order.

#include <iostream>
#include <unordered_map>

using namespace std;

int longest_consecutive_subsequence (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The length of the longest consecutive subsequence is: " << longest_consecutive_subsequence (arr, n) << endl;

	return 0;
}

int longest_consecutive_subsequence (int arr[], int n)
{
	unordered_map<int, int> ump;
	
	for (int i = 0; i < n; i++)
		ump[arr[i]]++;

	int curr_count, max_count = 1;
	for (int i = 0; i < n; i++)
	{
		curr_count = 1;	
		if (ump[arr[i]-1] > 0)	continue;

		int j = 1;
		while (ump[arr[i]+j++] > 0)
			curr_count++;
		
		if (curr_count > max_count)	max_count = curr_count;
	}

	return max_count;
}
