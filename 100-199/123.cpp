/*******************************************************************************
					123. The sum


time limit per test: 0.25 sec. 
memory limit per test: 4096 KB

The Fibonacci sequence of numbers is known: F1 = 1; F2 = 1; Fn+1 = Fn + Fn-1, for n>1. You have to find S - the sum of the first K Fibonacci numbers.

Input

First line contains natural number K (0<K<41).

Output

First line should contain number S.

Sample Input

 5
Sample Output

 12
*////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;

	int a(1),b(1),c(0);
	for(int i = 0;i < k;i++)
	{
		c = a+b;
		a = b;
		b = c;
	}

	cout << c-1;

	return 0;
}
