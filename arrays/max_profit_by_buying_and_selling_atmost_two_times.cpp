//Problem Statement: Given an array of integers containing stock prices throughout the day, find out the maximum profit
//		     that a share trader could have made.
//		     Constraint 1: The trader is allowed to make at most 2 transactions in a day.
//		     Constraint 2: The second transaction can start only after the first one is complete.

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int max_profit_by_buying_and_selling_twice (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "The maximum profit made is: " << max_profit_by_buying_and_selling_twice (arr, n) << endl;
	
	return 0;
}

int max_profit_by_buying_and_selling_twice (int arr[], int n)
{
	int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
	
	for (int i = 0; i < n; i++)
	{
		buy1  = max (buy1, -arr[i]);
		sell1 = max (sell1, buy1 + arr[i]);
		buy2 = max (buy2, sell1 - arr[i]);
		sell2 = max (sell2, buy2 + arr[i]);
		cout << "buy1 = " << buy1 << " sell1 = " << sell1 << endl;
		cout << "buy2 = " << buy2 << " sell2 = " << sell2 << endl << endl;
	}

	return sell2;
}
