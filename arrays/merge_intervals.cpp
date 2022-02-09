//Problem Statement: Given an array of intervals, merge all the overlapping intervals to form one single interval and
//		     display all the non-overlapping intervals at the end.
//		     Each interval consists of start time and end time.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int start_time, end_time;
	vector<pair<int, int>> vec;
	cout << "Enter the start time and the end time for each of the intervals of the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> start_time >> end_time;
		vec.push_back(make_pair(start_time, end_time));
	}

	sort (vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		if (vec[i].second > vec[i+1].first)
		{
			if (vec[i].second > vec[i+1].second)
			{
				vec.erase(vec.begin() + (i+1));
				n--;
			}
			else
			{
				vec[i].second = vec[i+1].second;
				vec.erase(vec.begin() + (i+1));
				n--;
			}
		}
	}

	cout << "The non-overlapping intervals are: ";
	for (auto x : vec)
		cout << "(" << x.first << ", " << x.second << ")  ";
	cout << endl;
	
	return 0;
}	
