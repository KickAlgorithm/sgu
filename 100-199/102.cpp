/*
 
 For given integer N (1<=N<=104) find amount of positive numbers not greater than N that coprime with N. Let us call two positive integers (say, A and B, for example) coprime if (and only if) their greatest common divisor is 1. (i.e. A and B are coprime iff gcd(A,B) = 1).
 
 Input
 
 Input file contains integer N.
 
 Output
 
 Write answer in output file.
 
 Sample Input
 
 9
 Sample Output
 
 6
 
 
 */

#include<iostream>
using namespace std;


int gcd ( int a, int b )
{
    int c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

int main()
{
    int N;
    cin >> N;
    int res = 0;
    for(int i = 1;i <= N;i++)
        if(gcd(i, N) == 1)
            res++;
    cout << res;
    return 0;
}
