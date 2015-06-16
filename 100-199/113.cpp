/***************************************************************************
113.Nearly prime numbers


time limit per test: 0.25 sec. 
memory limit per test: 4096 KB

Nearly prime number is an integer positive number for which it is possible to find such primes P1 and P2 that given number is equal to P1*P2. There is given a sequence on N integer positive numbers, you are to write a program that prints “Yes” if given number is nearly prime and “No” otherwise.

Input

Input file consists of N+1 numbers. First is positive integer N (1£N£10). Next N numbers followed by N. Each number is not greater than 109. All numbers separated by whitespace(s).

Output

Write a line in output file for each number of given sequence. Write “Yes” in it if given number is nearly prime and “No” in other case.

Sample Input

 1
6
Sample Output

 Yes
********************************************************************************/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

bool isPrime(int x) {
	if (x<2) return 0;
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return false;
	return true;
}


int main()
{
	int n = (int)sqrt(1000000000);
	int c = (int)sqrt(n);
	bool *bv = new bool[n+1];
	memset(bv, true, n+1);
	for(int i = 2;i <= c;i++)
		if(bv[i])
			for(int j = i*i;j < n; j += i)
				bv[j] = false;

	int N; 
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int e;
		cin >> e;
		int low = (int)sqrt(e);
		bool flag(false);
		for(int j = 2;j <= low && !flag;j++)
		{
			if(bv[j] && e % j == 0)
			{
				int divide = e/j;
				if(divide <= c && bv[divide]) flag = true;
				if(divide > c && isPrime(divide)) flag = true;
			}
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
