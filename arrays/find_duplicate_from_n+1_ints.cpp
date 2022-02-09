//Problem Statement: Given an unsorted array of n+1 integers, consisting of integers from range 1 to n,
//		     find the integer which is occurs twice in the array.
//Constraints: (1) The array must not be altered.`(2) Expected time complexity : Theta(n)
//	       (2) Expected space complexity: Theta(1)

#include <iostream>

using namespace std;

int find_the_duplicate (int arr[], int n);

int main()
{
	int k, n;
	cout << "Enter the size of the array: ";
	cin >> k;
	n = k - 1;

	int arr[n+1];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n+1; i++)
		cin >> arr[i];

	cout << "The duplicate number is: " << find_the_duplicate (arr, n) << endl;

	return 0;
}

int find_the_duplicate (int arr[], int n)
{
	int n_sum = 0;
	for (int i = 1; i <= n; i++)
		n_sum ^= i;

	int n1_sum = 0;
	for (int i = 0; i < n+1; i++)
		n1_sum ^= arr[i];

	int duplicate = n_sum ^ n1_sum;

	return duplicate;
}
