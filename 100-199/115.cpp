/**************************************************************************
					115. Calendar


time limit per test: 0.25 sec. 
memory limit per test: 4096 KB

First year of new millenium is gone away. In commemoration of it write a program that finds the name of the day of the week for any date in 2001.

Input

Input is a line with two positive integer numbers N and M, where N is a day number in month M. N and M is not more than 100.

Output

Write current number of the day of the week for given date (Monday – number 1, … , Sunday – number 7) or phrase “Impossible” if such date does not exist.

Sample Input

 21 10
Sample Output

 7
****************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int D, M;
	cin >> D >> M;
	int start = 0; //2001 01 01 is Monday	

	if(M < 1 || M > 12 || D < 1 || D > Month[M-1]) cout << "Impossible";
	else {
		int total(start);
		for(int i = 0;i < M-1;i++)
			total += Month[i];
		total += D;
		cout << 1 + (total-1)%7;
	}

	return 0;
}
