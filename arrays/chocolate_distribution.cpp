//Problem Statement: Given an array of integers representing packets with that many number of chocolates in it,
//		     distribute the packets among the students such that the difference in the number of chocolates
//		     between the packet with the most chocolates and that with the least chocolates is minimum.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cout << "Enter the number of packets of chocolates: ";
	cin >> n;

	int arr[n];
	cout << "Enter the number of chocolates contained in each packet: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int m;
	cout << "Enter the total number of students: ";
	cin >> m;

	sort (arr, arr+n);

	int diff = arr[m-1] - arr[0];
	int  start_indx = 0;
	int end_indx = m;
	for (int i = 1; i < n; i++)
	{
		if (i+m > n || arr[i+m-1]-arr[i] >= diff)	continue;

		diff = arr[i+m-1]-arr[i];
		start_indx = i;
		end_indx = i+m;
	}

	cout << "The highest difference in the number of chocolates received by the students is: " << diff << endl;
	cout << "The number of chocolates received by individual students are: ";
	for (int i = start_indx; i < end_indx; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
