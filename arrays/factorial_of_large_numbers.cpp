//Problem Statement: Given a large number, find its factorial.

#include <iostream>
#include <vector>

using namespace std;

void factorial (int num, vector<int>& fac, int& size);
void multiply (int num, vector<int>& fac, int& size);

int main()
{
	int num;
	cout << "Enter the number: ";
	cin >> num;

	vector<int> fac (1, 1);
	int size = 1;
	factorial (num, fac, size);

	cout << "Factorial of the number is: ";
	for (int i = size-1; i >= 0; i--)
		cout << fac[i];
	cout << endl;

	return 0;
}

void factorial (int num, vector<int>& fac, int& size)
{
	if (num == 0 || num == 1)	return;

	for (int i = 2; i <= num; i++)
		multiply (i, fac, size);
}

void multiply (int num, vector<int>& fac, int& size)
{
	int i, par_prod, dig, carry = 0;
	for (i = 0; i < size; i++)
	{
		par_prod = fac[i] * num + carry;
		dig = par_prod % 10;
		fac[i] = dig;
		carry = par_prod / 10;
	}

	while (carry != 0)
	{
		dig = carry % 10;
		fac.push_back(dig);
		size += 1;
		carry /= 10;
	}
}
