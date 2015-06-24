/*********************************************************************************************8
					108. Self-numbers 2


					time limit per test: 0.5 sec. 
					memory limit per test: 4096 KB

In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence 33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ... The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. Let the a[i] will be i-th self-number. There are thirteen self-numbers a[1]..a[13] less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97. (the first self-number is a[1]=1, the second is a[2] = 3, :, the thirteen is a[13]=97);

Input

Input contains integer numbers N, K, s1...sk. (1<=N<=107, 1<=K<=5000) delimited by spaces and line breaks.

Output

At first line you must output one number - the quantity of self-numbers in interval [1..N]. Second line must contain K numbers - a[s1]..a[sk], delimited by spaces. It`s a gaurantee, that all self-numbers a[s1]..a[sk] are in interval [1..N]. (for example if N = 100, sk can be 1..13 and cannot be 14, because 14-th self-number a[14] = 108, 108 > 100)

Sample Input

 100 10
1 2 3 4 5 6 7 11 12 13
Sample Output

13
1 3 5 7 9 20 31 75 86 97
********************************************************************************************/

#include<iostream>
using namespace std;

int apply(int d)
{
	int res(d);
	while(d > 0)
	{
		int tmp = d % 10;
		d = d/10;
		res  += tmp;
	}
	return res;
}



int main()
{
	bool flag[64] = {false};
	int N,K; cin >> N >> K;
	int res[1000000];
	int total(0);	

	for(int i = 1;i <= N;i++)
	{
		if(flag[i%64] == false)
		{
			res[total] = i;
			total++;
		}
		flag[i%64] = false;

		int tmp = apply(i);
		flag[tmp%64] = true;
	}

	cout << total << endl;
	while(K--)
	{
		int pos;
		cin >> pos;
		cout << res[pos-1] << " "; 
	}

	return 0;
}

