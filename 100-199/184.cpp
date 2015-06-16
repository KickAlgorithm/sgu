/*************************************************************************
				184. Patties

time limit per test: 0.25 sec.
memory limit per test: 4096 KB
input: standard input
output: standard output



Petya is well-known with his famous cabbage patties. Petya's birthday will come very soon, and he wants to invite as many guests as possible. But the boy wants everybody to try his specialty of the house. That's why he needs to know the number of the patties he can cook using the stocked ingredients. Petya has P grams of flour, M milliliters of milk and C grams of cabbage. He has plenty of other ingredients. Petya knows that he needs K grams of flour, R milliliters of milk and V grams of cabbage to cook one patty. Please, help Petya calculate the maximum number of patties he can cook.

Input
The input file contains integer numbers P, M, C, K, R and V, separated by spaces and/or line breaks (1 <= P, M, C, K, R, V <= 10000).

Output
Output the maximum number of patties Petya can cook.

Sample test(s)

Input
3000 1000 500 
30 15 60

Output
8
**************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int P, M, C, K, R, V;
	cin >> P >> M >> C >> K >> R >> V;

	int a = P/K;
	int b = M/R;
	int c = C/V;

	int maximum = 0;
	maximum = min(a, b);
	maximum = min(maximum, c);

	cout << maximum;

	return 0;
}
