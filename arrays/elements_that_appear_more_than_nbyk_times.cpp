//Problem Statement: Given an array of integers of length n and an integer k, print the elements that
//		     occur more than n/k times.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void elements_that_occur_more_than_nbyk_times_Ok_extra_space (int arr[], int n, int k, vector<int>& result_vec);
void elements_that_occur_more_than_nbyk_times_O1_extra_space (int arr[], int n, int k, vector<int>& result_vec);

int main()
{
	int n;
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int k;
	cout << "Enter the integer k: ";
	cin >> k;
	
	vector<int> result_vec;
	elements_that_occur_more_than_nbyk_times_Ok_extra_space (arr, n, k, result_vec);
	
	cout << "The elements that occur more than n/k times are (by using extra space): ";
	for (auto x : result_vec)
		cout << x << " ";
	cout << endl;
	
	result_vec.clear();
	elements_that_occur_more_than_nbyk_times_O1_extra_space (arr, n, k, result_vec);	

	cout << "The elements that occur more than n/k times are (by using extra space): ";
	for (auto x : result_vec)
		cout << x << " ";
	cout << endl;

	return 0;
}

void elements_that_occur_more_than_nbyk_times_Ok_extra_space (int arr[], int n, int k, vector<int>& result_vec)
{
	int nbyk = n / k;
	unordered_map<int, int> ump;

	for (int i = 0; i < n; i++)
		ump[arr[i]]++;

	for (auto x : ump)
		if (x.second > nbyk)
			result_vec.push_back(x.first);
}

void elements_that_occur_more_than_nbyk_times_O1_extra_space (int arr[], int n, int k, vector<int>& result_vec)
{
	int nbyk = n/k, count = 1, max_count = 1;
	
	sort (arr, arr+n);
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i-1])
		{
			count++;
			continue;
		}
	
		if (count > nbyk)	result_vec.push_back(arr[i-1]);
		count = 1;
	}
	if (count > nbyk)	result_vec.push_back(arr[n-1]);
}	
