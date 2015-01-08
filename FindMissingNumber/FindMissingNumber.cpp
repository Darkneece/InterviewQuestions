// FindMissingNumber.cpp : Defines the entry point for the console application.
//

#include <iostream>


int FindMissingNumber(int a[], int length)
{
	if (a[length] - a[0] == length)
	{
		return 0;
	}

	int binary_last = length - 1;
	int binary_first = 0;
	int binary_middle = (binary_last - binary_first) / 2;

	while (binary_last - binary_first > 1)
	{
		// on first half
		if (a[binary_middle] - a[binary_first] > binary_middle - binary_first)
		{
			binary_last = binary_middle;
			binary_middle = binary_first + (binary_last - binary_first) / 2;
		}
		// on last half
		else if (a[binary_last] - a[binary_middle] > binary_last - binary_middle)
		{
			binary_first = binary_middle;
			binary_middle += (binary_last - binary_first) / 2;
		}
	}
	
	return a[binary_first] + 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16 };

	int aa[10];

	aa[-1] = 20;

	int r = FindMissingNumber( a, sizeof(a) / sizeof(int) );

	std::cout << "r = " << r << std::endl;
	std::cin >> r;
	
	return 0;
}

