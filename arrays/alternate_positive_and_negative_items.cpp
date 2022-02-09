//Problem Statement: Given an array of integers, arrange the array to hold alternate positive and negative integers.
//		     Constraint 1: The numbers should be in the order in which they occur in the original array.
//		     Constraint 2: The expected space complexity is Theta(1).

#include <iostream>

using namespace std;

void alternate_positive_and_negative_elements (int arr[], int n);
bool sign (int a);

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	alternate_positive_and_negative_elements (arr, n);

	cout << "The final array is: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

void alternate_positive_and_negative_elements (int arr[], int n)
{
	int i = 0, j, temp; 
	while (i < n)
	{
		if (i % 2 == 0 && sign(arr[i]))	
		{
			i++;
			continue;
		}
		if (i % 2 == 1 && !sign(arr[i]))
		{
			i++;
			continue;
		}

		for (j = i+1; j < n && sign(arr[j]) == sign(arr[i]); j++);

		if (j == n)	break;

		temp = arr[j];
		for (j--; j >= i; j--)
			arr[j+1] = arr[j];
		arr[i++] = temp;
	}
}
		
bool sign (int a)
{
	if (a >= 0)	return 1;
	else	return 0;
}
