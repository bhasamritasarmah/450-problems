//This program takes in the array elements
//It then prints out the array in reversed order
//C++ STL has been used to accomplish this task here.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{ 
	int val;
	vector<int> vec;

	cout << "Enter the elements of the array: ";
	while (cin >> val)	
		vec.push_back (val);

	reverse (vec.begin(), vec.end());
	
	for (auto x : vec)
		cout << x << " ";
	cout << endl;
	
	return 0;
}


 
