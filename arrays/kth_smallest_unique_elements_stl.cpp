//The program takes as input an array of numbers and an integer k.
//It then outputs the kth smallest number in that array.
//This program considers that the array elements are unique.

#include <iostream>
#include <set>

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

	//Sorting the elements of the array in less than nlogn time
	set<int> st (arr, arr+n);
	//Initialising the iterator
	auto it = st.begin();
	//Taking the iterator to the desired position
	advance (it, k-1);

	cout << "The kth smallest element is: " << *it << endl;

	return 0;
}	


