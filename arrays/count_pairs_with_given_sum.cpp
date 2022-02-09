//Problem Statement: Given an array of integers, find the total number of pairs whose sum is equal to the given sum.
//		     Expected time complexity : Theta(n)

#include <iostream>
#include <unordered_map>

using namespace std;

int count_pairs_with_given_sum (int arr[], int n, int sum);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sum;
	cout << "Enter the required sum: ";
	cin >> sum;

	cout << "The number of pairs with the given sum is: " << count_pairs_with_given_sum (arr, n, sum) << endl;

	return 0;
}

int count_pairs_with_given_sum (int arr[], int n, int sum)
{
	int count_pairs = 0;
	unordered_map<int,int> ump;

	for (int i = 0; i < n; i++)
		ump[arr[i]]++;

	for (int i = 0; i < n; i++)
	{
		count_pairs += ump[sum - arr[i]];

		if (sum - arr[i] == arr[i])
			count_pairs--;
	}
	
	count_pairs /= 2;

	return count_pairs;
}
