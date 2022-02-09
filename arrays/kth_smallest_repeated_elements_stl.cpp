//This program takes in an array of numbers, alongwith an integer k.
//It then prints out the kth smallest number. The assumption is that there may be multiple instances of a single element.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int k;
	cout << "Enter the value of k: ";
	cin >> k;

	//Entering the elements of the array into a map, alongwith their frequencies.
	map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;

	int freq = 0;
	//A map contains elements in the increasing order. The moment the frequency of an element becomes equal to or crosses the value k, that element is the required element.
	for (auto x : mp)
	{
		freq += x.second;
		
		if (freq < k) continue;

		cout << "The kth smallest number is: " << x.first << endl;
		return 0;
	}

	cout << "Invalid input for k!" << endl;
	return 0;
}

