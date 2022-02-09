//This program takes in the array size, followed by the elements of the array.
//It then prints the elements of the array in reverse order.
//The approach used here is an recursive approach.

#include <iostream>

using namespace std;

void reverse_array (int arr[], int low, int high);
void print_reverse_array (int arr[], int n);

int main()
{
	int n;
	
	cout << "Enter the length of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	reverse_array (arr, 0, n-1);

	cout << "The reversed array is: " << endl;
	print_reverse_array (arr, n);

	return 0;
}

void reverse_array (int arr[], int low, int high)
{
	if (low >= high)	return;

	//swap the elements at position low and high
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;

	reverse_array (arr, low + 1, high - 1);
}

void print_reverse_array (int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
