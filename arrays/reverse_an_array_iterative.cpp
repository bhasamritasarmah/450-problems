//This program collects the size of array, followed by the elements of the array.
//It then prints out the array in reverse order.
//The approach used here is iterative approach.

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

	cout << "The reverse array is: " << endl;
	print_reverse_array (arr, n);

	return 0;
}

void reverse_array (int arr[], int low, int high)
{
	while (low < high)
	{
		//swapping the first and last elements, second and last second elements, and so on
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;

		low = low + 1;
		high = high - 1;
	}
}

void print_reverse_array (int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
