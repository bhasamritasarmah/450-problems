//Problem Statement: To rotate the elements of an array in the clockwise direction by one position.

#include <iostream>

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

	//The last element is collected in a temp variable. Every element is copied to the position right after it.
	//At last, the last element is copied to the first position.
	int temp = arr[n-1];
	for (int i = n-2; i >= 0; i--)
		arr[i+1] = arr[i];
	arr[0] = temp;

	cout << "The contents of the array after one rotation is:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
