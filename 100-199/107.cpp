/***************************************************************************
				107. 987654321 problem


time limit per test: 0.25 sec. 
memory limit per test: 4096 KB

For given number N you must output amount of N-digit numbers, such, that last digits of their square is equal to 987654321.

Input

Input contains integer number N (1<=N<=106)

Output

Write answer to the output.

Sample Input

 8
Sample Output

 0
****************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	//for(long long int i = 1;i <= 999999999;i++)
	//	if(i*i % 1000000000 == 987654321)
	//		cout << i << endl;

	int N;
	cin >> N;

	if(N <= 8) cout << 0;
	else if(N == 9) cout << 8;
	else {
		cout << 72;
		string str(N-10,'0');
		cout << str;
	}	
	

	return 0;
}
