//Problem Statement: Given an array of integers, corresponding to heights, and an integer k,
//		     the task is to either add or subtract k from each of the elements of the
//		     array so that, the maximum difference between the maximum height and the
//		     minimum height is minimised.

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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

	int k;
	cout << "Enter the value of k: ";
	cin >> k;

	sort(arr, arr+n);

	cout << "The sorted array is given by - ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	vector<pair<int, int>> vec;
	int distinct = 0;
	map<int, int> mp;

	vec.push_back(make_pair(arr[0]-k, arr[0]));
	vec.push_back(make_pair(arr[0]+k, arr[0]));
	distinct++;

	for (int i = 1; i < n; i++)
	{
		if(arr[i] == arr[i-1])	continue;
		
		vec.push_back(make_pair(arr[i]-k, arr[i]));
		vec.push_back(make_pair(arr[i]+k, arr[i]));
		distinct++;
		mp[arr[i]] = 0;
	}	
	
	sort(vec.begin(), vec.end());

	cout << "The sorted vector is given by - ";
	for (auto x : vec)
		cout << "(" << x.first << ", " << x.second  << ") ";
	cout << endl;
	
	int diff;
	diff = vec[vec.size()-1].first - vec[0].first;
	cout << "Current difference = " << diff << endl;
	int left = 0, right = 0, count = 0;

	while (right < vec.size())
	{
		while (right < vec.size() && count < distinct)
		{
			if (mp[vec[right].second] == 0)	count++;

			mp[vec[right].second]++;
			right++;
		}
		
		if (right == vec.size() && count < distinct)	break;
		
		diff = min(diff, vec[right-1].first - vec[left].first);

		while (left <= right && count >= distinct)
		{
			if (mp[vec[left].second] == 1)	count--;

			mp[vec[left].second]--;	
			
			diff = min(diff, vec[right-1].first - vec[left].first);
			left++;
		}
	}

	cout << "The required minimum height difference is " << diff << endl;

	return 0;
}
