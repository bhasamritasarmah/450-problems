//Problem Statement: Given an array of integers that correspond to the sizes of stocks on different days.
//		     Find the appropriate days to buy and sell stock so that the profit gained is maximum.

#include <iostream>

using namespace std;

int best_time_to_buy_and_sell_stock (int arr[], int n);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << "The maximum profit that can be obtained is: " << best_time_to_buy_and_sell_stock (arr, n) << endl;
	
	return 0;
}

int best_time_to_buy_and_sell_stock (int arr[], int n)
{
	int buy = 0, sell = 1, profit = 0;

	while (sell < n)
	{
		if (arr[buy] < arr[sell])
			profit = max (profit, arr[sell]-arr[buy]);
		else
			buy = sell;
		sell++;
	}
	
	return profit;
}
