/**********************************************************************************
										117. Counting


									time limit per test: 0.25 sec. 
									memory limit per test: 4096 KB

Find amount of numbers for given sequence of integer numbers such that after raising them to the M-th power they will be divided by K.

Input

Input consists of two lines. There are three integer numbers N, M, K (0<N, M, K<10001) on the first line. There are N positive integer numbers − given sequence (each number is not more than 10001) − on the second line.

Output

Write answer for given task.

Sample Input

4 2 50
9 10 11 12
Sample Output

1
******************************************************************************************/

#include<iostream>
using namespace std;

int modexp(int a,int b,int n)     
{     
	int ret=1;     
    int tmp=a;     
    while(b)     
    {     
       //基数存在     
       if(b&0x1) ret=ret*tmp%n;     
       tmp=tmp*tmp%n;     
       b>>=1;     
    }     
    return ret;     
}     

int main()
{
	int N,M,K;
	cin >> N >> M >> K;
	int ans(0);

	for(int i = 0;i < N;i++)
	{
		int tmp;
		cin >> tmp;
		if (modexp(tmp, M, K) == 0)
			ans++;
	}
	cout << ans;
	
	return 0;
}
