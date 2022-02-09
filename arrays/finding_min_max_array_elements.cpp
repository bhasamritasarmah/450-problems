//This program takes in the array size, followed by the elements of the array.
//It then gives out the minimum, and the maximum elements respectively.

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

	//The min_arr and max_arr will contain a total of (n/2 + 1) elements if n is odd, and n/2 elements if n is even.
	int min_arr[n/2 + 1], max_arr[n/2 + 1], j = 0;
	cout << "j = " << n/2 + 1 << endl;
	for (int i = 0; i < n-1; i+=2)
	{
		//Every two elenents are checked. The larger of the two is put into the max_arr, and the smalller of the two is put into the min_arr.
		if (arr[i] > arr[i+1])
		{
			max_arr[j] = arr[i];
			min_arr[j] = arr[i+1];
		}
		else
		{
			min_arr[j] = arr[i];
			max_arr[j] = arr[i+1];
		}	
		j++;
	}

	//If n is odd then the last element is put in both the arrays.
	if (n % 2 == 1)
	{
		max_arr[j] = arr[n-1];
		min_arr[j] = arr[n-1];
		j++;
	}

	//The maximum element of max_arr will be the maximum element of arr.
	//The minimum element of min_arr will be the minimum element of arr.
	int max = max_arr[0], min = min_arr[0];	
	for (int i = 0; i < j; i++)
	{
		if (max < max_arr[i])
			max = max_arr[i];
		if (min > min_arr[i])
			min = min_arr[i];
	}
		
	cout << "The max element is: " << max << endl;
	cout << "The min element is: " << min << endl;
	
	return 0;
}
	

